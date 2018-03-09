/**********************************************************************
 *
 * sstDxf03Lib - sst dxf library
 * Hosted on github
 *
 * Copyright (C) 2016 Uli Rehr
 *
 * This file may be distributed and/or modified under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation and appearing in the file gpl-2.0.txt included in the
 * packaging of this file.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * This copyright notice MUST APPEAR in all copies of the script!
 *
**********************************************************************/
// sstDxf03Block.cpp   01.11.16  Re.   26.02.16  Re.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <string>
#include <list>

#include <dl_dxf.h>
#include <dl_creationadapter.h>

#include <rs_vector.h>

#include <sstStr01Lib.h>
#include <sstMath01Lib.h>
#include <sstMisc01Lib.h>
#include <sstRec04Lib.h>
#include <sstDxf03Lib.h>

#include "sstDxf03LibInt.h"

//=============================================================================
sstDxf03TypBlkCls::sstDxf03TypBlkCls()
{
  this->ulBlockID = 0;
  memset(this->Nam,0,dSSTDXF03BLOCKNAMELEN);
  this->flags = 0;
}
//=============================================================================
int sstDxf03TypBlkCls::getFlags() const
{
return flags;
}
//=============================================================================
void sstDxf03TypBlkCls::setFlags(int value)
{
flags = value;
}
//=============================================================================
char* sstDxf03TypBlkCls::getName()
{
  return this->Nam;
}
//=============================================================================
void sstDxf03TypBlkCls::setName(const char* cTmpName)
{
  strncpy(this->Nam,cTmpName,dSSTDXF03LAYERNAMELEN);
}

unsigned long sstDxf03TypBlkCls::getBlockID() const
{
return ulBlockID;
}

void sstDxf03TypBlkCls::setBlockID(unsigned long value)
{
ulBlockID = value;
}
//=============================================================================
void sstDxf03TypBlkCls::ReadFromDL(const DL_BlockData oDlBlk)
{
  strncpy(this->Nam, oDlBlk.name.c_str(), dSSTDXF03BLOCKNAMELEN);
  this->flags = oDlBlk.flags;
}
//=============================================================================
void sstDxf03TypBlkCls::WritToDL(DL_BlockData *poDlBlk)
{
    poDlBlk->name = this->getName();
    poDlBlk->flags = this->getFlags();
}
//=============================================================================
int sstDxf03TypBlkCls::updateMbr (int iKey, sstMath01Mbr2Cls oTmpMbr)
{
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;
  int iStat = 0;
  iStat = this->oMbr.Koor2(0,oTmpMbr.getXA(),oTmpMbr.getYA());
  iStat = this->oMbr.Koor2(0,oTmpMbr.getXI(),oTmpMbr.getYI());
  return iStat;
}
//=============================================================================
sstMath01Mbr2Cls sstDxf03TypBlkCls::getMbr() const
{
  return this->oMbr;
}
//=============================================================================
// Constructor
sstDxf03FncBlkCls::sstDxf03FncBlkCls():sstDxf03FncBaseCls(sizeof(sstDxf03TypBlkCls))
{
  sstDxf03TypBlkCls oBlkRec;
  // Init new name Tree sorting object for Block RecMem object
  int iStat = this->TreIni( 0, &oBlkRec, &oBlkRec.Nam, sizeof(oBlkRec.Nam), sstRecTyp_CC, &this->oBlockTree);
  assert(iStat == 0);
  this->dBlockMdlRecNo = 0;
}
//=============================================================================
// Csv Read Function
int sstDxf03FncBlkCls::Csv_Read(int iKey, std::string *sErrTxt, std::string *ssstDxfLib_Str, sstDxf03TypBlkCls *oSstBlk)
{
  DL_BlockData sDlBlk("",0,0.0,0.0,0.0);
  // sstStr01Cls oCsvRow;
  unsigned long ulTmpBlockID = 0;
  int iStat = 0;
  int iRet  = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  oCsvRow.SetReadPositon(0,0);

  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_UInt4( 0, ssstDxfLib_Str, &ulTmpBlockID);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Str( 0, ssstDxfLib_Str, &sDlBlk.name);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Int2( 0, ssstDxfLib_Str, &sDlBlk.flags);
  if (iStat >= 0)

  *sErrTxt = oCsvRow.GetErrorString();

  oSstBlk->ReadFromDL(sDlBlk);
  oSstBlk->setBlockID(ulTmpBlockID);

  // read base dxf attributes from csv string
  if (iStat >= 0)
    iStat = this->Csv_BaseRead2(0, sErrTxt, ssstDxfLib_Str, oSstBlk);

  // Fatal Errors goes to an assert
  if (iRet < 0)
  {
    // Expression (iRet >= 0) has to be fullfilled
    assert(0);
  }

  // Small Errors will given back
  iRet = iStat;

//  Bloc Function1 End
  return iStat;
}

// Csv Write Function
int sstDxf03FncBlkCls::Csv_Write(int iKey, sstDxf03TypBlkCls *poSstBlk, std::string *ssstDxfLib_Str)
{
  // sstStr01Cls oCsvRow;  // Csv String Convert object
  int iStat = 0;

  //  Bloc Function Write Start
  int iRet  = 0;
  if ( iKey != 0) return -1;

  ssstDxfLib_Str->clear();

  if (iStat >= 0)
    iStat = oCsvRow.Csv_UInt4_2String( 0, poSstBlk->getBlockID(), ssstDxfLib_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Char_2String( 0, poSstBlk->getName(), ssstDxfLib_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Int2_2String ( 0, poSstBlk->getFlags(), ssstDxfLib_Str);

  // write base dxf attributes to csv string
  if (iStat >= 0)
    iStat = this->Csv_BaseWrite2 ( 0, *poSstBlk, ssstDxfLib_Str);

  // Fatal Errors goes to an assert
  if (iRet < 0)
  {
    // Expression (iRet >= 0) has to be fullfilled
    assert(0);
  }

  // Small Errors will given back
  iRet = iStat;

//  Bloc Function Write End
  return iStat;
}
//=============================================================================
int sstDxf03FncBlkCls::Csv_WriteHeader(int iKey, std::string *ssstDxfLib_Str)
{
  std::string oTitelStr;
  int iStat = 0;

//  char Nam[dSSTDXF03BLOCKNAMELEN];  /**< Block Name */
//  int  flags;               /**< Block Flags */

  if ( iKey != 0) return -1;

  ssstDxfLib_Str->clear();

  oTitelStr = "BlockID";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "name";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "flags";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);

  // append base attributes to block csv titel row
  this->Csv_BaseHeader2(0,ssstDxfLib_Str);

  // Fatal Errors goes to an assert
  if (iStat < 0)
  {
    // Expression (iRet >= 0) has to be fullfilled
    assert(0);
  }

  return iStat;
}
//=============================================================================
sstRec04TreeKeyCls* sstDxf03FncBlkCls::getNameSortKey()
{
  return &this->oBlockTree;
}
//=============================================================================
int sstDxf03FncBlkCls::ReadCsvFile(int iKey, std::string oFilNam)
{
  sstMisc01AscFilCls oCsvFilLayer;
  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  iStat = oCsvFilLayer.fopenRd(0,oFilNam.c_str());
  if (iStat < 0) return -2;
  // assert(iStat==0);

  // sstDxf03FncLayCls oSstFncLay;  // layer recmem object
  std::string oLayStr;
  std::string oErrStr;
  dREC04RECNUMTYP dRecNo = 0;
  int iStat1 = 0;
  // Read title row
  iStat1 = oCsvFilLayer.Rd_StrDS1 ( 2, &oLayStr);
  if (iStat1 < 0) return -3;

  // Read first data row
  iStat1 = oCsvFilLayer.Rd_StrDS1 ( 2, &oLayStr);
  while (iStat1 >= 0)
  {
    sstDxf03TypBlkCls oSstBlk;
    // Read layer object from string row
    iStat = this->Csv_Read( 0, &oErrStr, &oLayStr, &oSstBlk);
    if (iStat < 0)
    {
      iStat1 = -1;
      iStat = -4;
      break;
    }
    // write layer object to recmem
    this->WritNew(0,&oSstBlk,&dRecNo);

    // Read next row from layer csv file
    oLayStr.clear();
    iStat1 = oCsvFilLayer.Rd_StrDS1 ( 2, &oLayStr);
  }

  oCsvFilLayer.fcloseFil(0);

  return iStat;
}
//=============================================================================
int sstDxf03FncBlkCls::WriteCsvFile(int iKey, std::string oDxfFilNam)
{
  sstMisc01AscFilCls oCsvFil;
  std::string oCsvFilNam;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  // ===== Write all block data to Csv file
  oCsvFilNam = oDxfFilNam + "_Block.csv";
  int iStat = oCsvFil.fopenWr(0,(char*) oCsvFilNam.c_str());
  assert(iStat >= 0);

  std::string oCsvStr;

  this->Csv_WriteHeader(0,&oCsvStr);
  oCsvFil.Wr_StrDS1(0, &oCsvStr);

  for(dREC04RECNUMTYP kk = 1; kk <= this->count(); kk++)
  {

    sstDxf03TypBlkCls oDxfBlk;
    iStat = this->Read(0,kk,&oDxfBlk);

    oDxfBlk.setBlockID(kk);

    this->Csv_Write( 0, &oDxfBlk, &oCsvStr);
    oCsvFil.Wr_StrDS1(0, &oCsvStr);
  }

  iStat = oCsvFil.fcloseFil(0);
  return iStat;
}
//=============================================================================
sstMath01Mbr2Cls sstDxf03FncBlkCls::getMbrModel()
{

  int iStat = this->TreBld(0,&this->oBlockTree);
  assert(iStat >= 0);

  sstMath01Mbr2Cls oMbr;
  std::string oBlkStr = "*Model_Space";
  dREC04RECNUMTYP dBlkRecNo=0;
  // iStat = this->TreSeaEQ( 0, this->getNameSortKey(), (void*) oBlkStr.c_str(), &dBlkRecNo);
  iStat = this->TreSeaEQ( 0, &this->oBlockTree, (void*) oBlkStr.c_str(), &dBlkRecNo);
  assert(iStat == 1);
  sstDxf03TypBlkCls oBlkRec;
  this->Read(0,dBlkRecNo,&oBlkRec);

  return oBlkRec.getMbr();
}
//=============================================================================
int sstDxf03FncBlkCls::updateMbrModel(int iKey, sstMath01Mbr2Cls oMbr)
{
    if ( iKey != 0) return -1;

    sstDxf03TypBlkCls oBlkRec;
    int iStat = this->Read(0,this->getBlockMdlRecNo(),&oBlkRec);
    assert(iStat == 0);
    // sstMath01Mbr2Cls oMdlMbr;
    oBlkRec.updateMbr(0,oMbr);

    iStat = this->Writ(0,&oBlkRec,this->getBlockMdlRecNo());

    return iStat;
}
//=============================================================================
int sstDxf03FncBlkCls::updateMbrBlock(int iKey,   dREC04RECNUMTYP dBlkNo, sstMath01Mbr2Cls oMbr)
{
    if ( iKey != 0) return -1;

    sstDxf03TypBlkCls oBlkRec;
    int iStat = this->Read( 0, dBlkNo, &oBlkRec);
    assert(iStat == 0);
    // sstMath01Mbr2Cls oMdlMbr;
    oBlkRec.updateMbr(0,oMbr);

    iStat = this->Writ( 0, &oBlkRec, dBlkNo);

    return iStat;
}
//=============================================================================
dREC04RECNUMTYP sstDxf03FncBlkCls::getBlockMdlRecNo() const
{
return dBlockMdlRecNo;
}
//=============================================================================
void sstDxf03FncBlkCls::setBlockMdlRecNo(dREC04RECNUMTYP value)
{
  dBlockMdlRecNo = value;
}
//=============================================================================
