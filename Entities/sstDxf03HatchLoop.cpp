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
//  sstDxf03HatchLoop.cpp   01.11.16  Re.   29.04.16  Re.
//
//  Functions for sst Dxf Hatch Loop Classes
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
// Constructor
sstDxf03TypHatchLoopCls::sstDxf03TypHatchLoopCls()
{
  this->dRecordID = 0;
  this->numEdges = 0;
}
//=============================================================================
// Set Test Data
int sstDxf03TypHatchLoopCls::SetTestData(int iKey)
{
  if ( iKey != 0) return -1;

  this->dRecordID = 5;
  this->numEdges = 1;
  return 0;
}
//=============================================================================
void sstDxf03TypHatchLoopCls::ReadFromDL(const DL_HatchLoopData oDLHatchLoop)
{
  this->numEdges = oDLHatchLoop.numEdges;
}
//=============================================================================
void sstDxf03TypHatchLoopCls::WritToDL(DL_HatchLoopData *poDLHatchLoop)
{
  poDLHatchLoop->numEdges = this->numEdges;
}
//=============================================================================
dREC04RECNUMTYP sstDxf03TypHatchLoopCls::getRecordID() const
{
return dRecordID;
}
//=============================================================================
void sstDxf03TypHatchLoopCls::setRecordID(const dREC04RECNUMTYP &value)
{
dRecordID = value;
}
//=============================================================================
int sstDxf03TypHatchLoopCls::getNumEdges() const
{
return numEdges;
}
//=============================================================================
void sstDxf03TypHatchLoopCls::setNumEdges(int value)
{
numEdges = value;
}
//=============================================================================
// Constructor
sstDxf03FncHatchLoopCls::sstDxf03FncHatchLoopCls():sstDxf03FncBaseCls(sizeof(sstDxf03TypHatchLoopCls))
{
  // this->poDxfArcMem = new sstRec04Cls(sizeof(sstDxf03TypHatchLoopCls));
}
//=============================================================================
// Csv Read Function
int sstDxf03FncHatchLoopCls::Csv_Read(int iKey, std::string *sErrTxt, std::string *ssstDxfLib_Str, sstDxf03TypHatchLoopCls *osstDxf02TypHatchLoop)
{
  dREC04RECNUMTYP dLocRecordID = 0;
  int iLocNumEdges;

  int iStat = 0;
  int iRet  = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  oCsvRow.SetReadPositon(0,0);

  //  int numEdges;

  if (iStat >= 0) iStat = oCsvRow.CsvString2_UInt4( 0, ssstDxfLib_Str, &dLocRecordID);
  if (iStat >= 0) osstDxf02TypHatchLoop->setRecordID(dLocRecordID);

  if (iStat >= 0) iStat = oCsvRow.CsvString2_Int2( 0, ssstDxfLib_Str, &iLocNumEdges);
  if (iStat >= 0) osstDxf02TypHatchLoop->setNumEdges(iLocNumEdges);

  *sErrTxt = oCsvRow.GetErrorString();

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
//=============================================================================
// Csv Write Function
int sstDxf03FncHatchLoopCls::Csv_Write(int iKey, sstDxf03TypHatchLoopCls *poSstHatchLoop, std::string *ssstDxfLib_Str)
{
  int iStat = 0;

  if ( iKey != 0) return -1;

  ssstDxfLib_Str->clear();

  if (iStat >= 0) iStat = oCsvRow.Csv_UInt4_2String( 0, poSstHatchLoop->getRecordID(), ssstDxfLib_Str);
  if (iStat >= 0) iStat = oCsvRow.Csv_Int2_2String( 0, poSstHatchLoop->getNumEdges(), ssstDxfLib_Str);


  //  int numEdges;

  return iStat;
}
//=============================================================================
int sstDxf03FncHatchLoopCls::Csv_WriteHeader(int iKey, std::string *ssstDxfLib_Str)
{
  std::string oTitelStr;
  int iStat = 0;

  if ( iKey != 0) return -1;

  ssstDxfLib_Str->clear();

  //  int numEdges;

  oTitelStr = "RecordID";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "NumEdges";
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
int sstDxf03FncHatchLoopCls::ReadCsvFile(int iKey, std::string oFilNam)
{
  sstMisc01AscFilCls oCsvFilLayer;
  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  iStat = oCsvFilLayer.fopenRd(0,oFilNam.c_str());
  if (iStat < 0) return -2;

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
    sstDxf03TypHatchLoopCls oSstArc;
    // Read layer object from string row
    iStat = this->Csv_Read( 0, &oErrStr, &oLayStr, &oSstArc);
    if (iStat < 0)
    {
      iStat1 = -1;
      iStat = -4;
      break;
    }
    // write layer object to recmem
    this->WritNew(0,&oSstArc,&dRecNo);
    // Read next row from layer csv file
    oLayStr.clear();
    iStat1 = oCsvFilLayer.Rd_StrDS1 ( 2, &oLayStr);
  }

  oCsvFilLayer.fcloseFil(0);

  return iStat;
}
//=============================================================================
int sstDxf03FncHatchLoopCls::WriteCsvFile(int iKey, std::string oDxfFilNam)
{
  sstMisc01AscFilCls oCsvFil;
  std::string oCsvFilNam;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  // ===== Write all Insert to Csv file
  oCsvFilNam = oDxfFilNam + "_HatchLoop.csv";
  int iStat = oCsvFil.fopenWr(0,(char*) oCsvFilNam.c_str());
  assert(iStat >= 0);

  std::string oCsvStr;

  this->Csv_WriteHeader(0,&oCsvStr);
  oCsvFil.Wr_StrDS1(0, &oCsvStr);

  for(dREC04RECNUMTYP kk = 1; kk <= this->count(); kk++)
  {

    sstDxf03TypHatchLoopCls oDxfHatchLoop;
    iStat = this->Read(0,kk,&oDxfHatchLoop);

    oDxfHatchLoop.setRecordID(kk);

    this->Csv_Write( 0, &oDxfHatchLoop, &oCsvStr);
    oCsvFil.Wr_StrDS1(0, &oCsvStr);
  }

  iStat = oCsvFil.fcloseFil(0);
  return iStat;
}
//=============================================================================
