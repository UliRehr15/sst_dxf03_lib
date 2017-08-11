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
//  sstDxf03LType.cpp   01.11.16  Re.   10.06.16  Re.
//
//  Functions for sst Dxf LType Classes
//

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
sstDxf03TypLTypeCls::sstDxf03TypLTypeCls()
{

}
//=============================================================================
char* sstDxf03TypLTypeCls::getName()
{
  return this->Nam;
}
//=============================================================================
dREC04RECNUMTYP sstDxf03TypLTypeCls::getLineTypeID() const
{
return dLineTypeID;
}
//=============================================================================
void sstDxf03TypLTypeCls::setLineTypeID(const dREC04RECNUMTYP &value)
{
dLineTypeID = value;
}
//=============================================================================
void sstDxf03TypLTypeCls::setName(const std::string oTmpName)
{
  strncpy(this->Nam,oTmpName.c_str(),dSSTDXF03LTYPENAMELEN);
}
//=============================================================================
int sstDxf03TypLTypeCls::getSizeName() const
{
  return sizeof(this->Nam);
}
//=============================================================================

sstDxf03FncLTypeCls::sstDxf03FncLTypeCls():sstDxf03FncBaseCls(sizeof(sstDxf03TypLTypeCls))
{
  sstDxf03TypLTypeCls oLTypeRec;
  // Init new name Tree sorting object for Linetype table object
  int iStat = this->TreIni( 0, &oLTypeRec, oLTypeRec.getName(), oLTypeRec.getSizeName(), sstRecTyp_CC, &this->oLTypeTree);
  assert(iStat == 0);
}
//=============================================================================
int sstDxf03FncLTypeCls::WriteNewUnique(int iKey, sstDxf03TypLTypeCls oLTypeRec, dREC04RECNUMTYP *dLTypeRecNo)
{
  if ( iKey != 0) return -1;

  int iStat = 0;

  // Find record with exact search value
  iStat = this->TreSeaEQ( 0, this->getNameSortKey(), (char*) oLTypeRec.getName(), dLTypeRecNo);

  if (*dLTypeRecNo == 0)
  {
    *dLTypeRecNo = this->count();
    oLTypeRec.setLineTypeID(*dLTypeRecNo+1);
    // Write new record into record memory and update all trees
    iStat = this->TreWriteNew( 0, &oLTypeRec, dLTypeRecNo);
    assert(iStat == 0);
  }

  return iStat;
}
//=============================================================================
int sstDxf03FncLTypeCls::Csv_Read(int iKey, std::string *sErrTxt, std::string *oCsvStr, sstDxf03TypLTypeCls *oTypLType)
{
  unsigned long ulTmpLTypeID = 0;
  std::string oTmpStr;

  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  oCsvRow.SetReadPositon(0,0);

  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_UInt4( 0, oCsvStr, &ulTmpLTypeID);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Str( 0, oCsvStr, &oTmpStr);

  if (iStat >= 0)
  {
    oTypLType->setLineTypeID(ulTmpLTypeID);
    oTypLType->setName(oTmpStr.c_str());
  }
  else
  {
    *sErrTxt = oCsvRow.GetErrorString();
  }

  return iStat;
}
//=============================================================================
// Csv Write Function
int sstDxf03FncLTypeCls::Csv_Write(int iKey, sstDxf03TypLTypeCls *poSstLType, std::string *ssstDxfLib_Str)
{
  // sstStr01Cls oCsvRow;  // Csv String Convert object
  int iStat = 0;

  //  Bloc Function Write Start
  int iRet  = 0;
  if ( iKey != 0) return -1;

  ssstDxfLib_Str->clear();

  if (iStat >= 0)
    iStat = oCsvRow.Csv_UInt4_2String( 0, poSstLType->getLineTypeID(), ssstDxfLib_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Char_2String( 0, poSstLType->getName(), ssstDxfLib_Str);

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
int sstDxf03FncLTypeCls::Csv_WriteHeader(int iKey, std::string *ssstDxfLib_Str)
{
  std::string oTitelStr;
  int iStat = 0;

  if ( iKey != 0) return -1;

  ssstDxfLib_Str->clear();

  oTitelStr = "LineTypeID";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "Name";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);

  // Fatal Errors goes to an assert
  if (iStat < 0)
  {
    // Expression (iRet >= 0) has to be fullfilled
    assert(0);
  }

  return iStat;
}
//=============================================================================
sstRec04TreeKeyCls* sstDxf03FncLTypeCls::getNameSortKey()
{
  return &this->oLTypeTree;
}
//=============================================================================
int sstDxf03FncLTypeCls::ReadCsvFile(int iKey, std::string oFilNam)
{
  sstMisc01AscFilCls oCsvFilLayer;
  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  iStat = oCsvFilLayer.fopenRd(0,oFilNam.c_str());
  // assert(iStat==0);
  if (iStat < 0) return -2;

  std::string oLTypeStr;
  std::string oErrStr;
  dREC04RECNUMTYP dRecNo = 0;
  int iStat1 = 0;

  // Read title row
  iStat1 = oCsvFilLayer.Rd_StrDS1 ( 2, &oLTypeStr);
  if (iStat < 0) return -3;

  // Read first data row
  iStat1 = oCsvFilLayer.Rd_StrDS1 ( 2, &oLTypeStr);

  while (iStat1 >= 0)
  {
    sstDxf03TypLTypeCls oSstLType;
    // Read layer object from string row
    iStat = this->Csv_Read( 0, &oErrStr, &oLTypeStr, &oSstLType);
    if (iStat < 0)
    {
      iStat1 = -1;
      iStat = -4;
      break;
    }
    // write layer object to recmem
    this->WritNew(0,&oSstLType,&dRecNo);
    // Read next row from layer csv file
    oLTypeStr.clear();
    iStat1 = oCsvFilLayer.Rd_StrDS1 ( 2, &oLTypeStr);
  }

  oCsvFilLayer.fcloseFil(0);

  return iStat;
}
//=============================================================================
int sstDxf03FncLTypeCls::WriteCsvFile(int iKey, std::string oDxfFilNam)
{
  sstMisc01AscFilCls oCsvFil;
  std::string oCsvFilNam;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  // ===== Write all Layer data to Csv file
  oCsvFilNam = oDxfFilNam + "_Linetype.csv";
  int iStat = oCsvFil.fopenWr(0,(char*) oCsvFilNam.c_str());
  assert(iStat >= 0);

  std::string oCsvStr;

  this->Csv_WriteHeader(0,&oCsvStr);
  oCsvFil.Wr_StrDS1(0, &oCsvStr);

  for(dREC04RECNUMTYP kk = 1; kk <= this->count(); kk++)
  {

    sstDxf03TypLTypeCls oDxfLType;
    iStat = this->Read(0,kk,&oDxfLType);

    this->Csv_Write( 0, &oDxfLType, &oCsvStr);
    oCsvFil.Wr_StrDS1(0, &oCsvStr);
  }

  iStat = oCsvFil.fcloseFil(0);
  return iStat;
}
//=============================================================================
