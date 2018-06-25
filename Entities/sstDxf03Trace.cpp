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
//  sstDxf03Trace.cpp   12.06.18  Re.     12.06.18  Re.
//
//  Functions for Class "sstDxf03Trace"
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

//  sstDxf03TypTrace.cpp   21.03.18  Re.   21.03.18  Re.
//
//  Functions for Class "sstDxf03"
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <string>

#include <sstStr01Lib.h>
#include <sstMath01Lib.h>
#include <sstMisc01Lib.h>
#include <sstRec04Lib.h>
#include <sstDxf03Lib.h>

#include "sstDxf03LibInt.h"

// Constructor
sstDxf03TypTraceCls::sstDxf03TypTraceCls()
{

}

// Get Number of Class member
unsigned int sstDxf03TypTraceCls::getMemberNumber()
{
  unsigned int uiStat = 0;
  uiStat = 13;
  return uiStat;
}

// Get Csv-String with all Class member names
std::string sstDxf03TypTraceCls::getStringName()
{
  std::string oStat;
  oStat = "sx1;sy1;sz1;sx2;sy2;sz2;sx3;sy3;sz3;sx4;sy4;sz4;thickness";
  return oStat;
}

// Get Csv-String with all Class member definition types
std::string sstDxf03TypTraceCls::getStringType()
{
  std::string oStat;
  oStat = "DD12.4;DD12.4;DD12.4;DD12.4;DD12.4;DD12.4;DD12.4;DD12.4;DD12.4;DD12.4;DD12.4;DD12.4;DD12.4";
  return oStat;
}

// Csv Read Function
int sstDxf03TypTraceCls::Csv_Read(int iKey, std::string *sErrTxt, std::string *ssstDxf03_Str)
{
  int iStat = 0;
//  sstStr01Cls sErrTxt;
  sstStr01Cls oCsvRow;
  int iRet  = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  iStat = oCsvRow.SetReadPositon(0,0);

  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf03_Str, &this->sx1);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf03_Str, &this->sy1);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf03_Str, &this->sz1);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf03_Str, &this->sx2);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf03_Str, &this->sy2);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf03_Str, &this->sz2);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf03_Str, &this->sx3);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf03_Str, &this->sy3);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf03_Str, &this->sz3);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf03_Str, &this->sx4);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf03_Str, &this->sy4);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf03_Str, &this->sz4);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf03_Str, &this->thickness);

  *sErrTxt = oCsvRow.GetErrorString();

  // Fatal Errors goes to an assert
  if (iRet < 0)
  {
    // Expression (iRet >= 0) has to be fullfilled
    assert(0);
  }

  // Small Errors will given back
  iRet = iStat;

  return iStat;
}

// Csv Write Function
int sstDxf03TypTraceCls::Csv_Write(int iKey , std::string *ssstDxf03_Str)
{
  int iStat = 0;
  sstStr01Cls oCsvRow;
  int iRet  = 0;
  if ( iKey != 0) return -1;

  iStat = oCsvRow.SetReadPositon(0,0);

  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, this->sx1, ssstDxf03_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, this->sy1, ssstDxf03_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, this->sz1, ssstDxf03_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, this->sx2, ssstDxf03_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, this->sy2, ssstDxf03_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, this->sz2, ssstDxf03_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, this->sx3, ssstDxf03_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, this->sy3, ssstDxf03_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, this->sz3, ssstDxf03_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, this->sx4, ssstDxf03_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, this->sy4, ssstDxf03_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, this->sz4, ssstDxf03_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, this->thickness, ssstDxf03_Str);

  // Fatal Errors goes to an assert
  if (iRet < 0)
  {
    // Expression (iRet >= 0) has to be fullfilled
    assert(0);
  }

  // Small Errors will given back
  iRet = iStat;

  return iStat;
}
//=============================================================================
void sstDxf03TypTraceCls::ReadFromDL(const DL_TraceData oDLTrace)
{
  this->sx1 = oDLTrace.x[0];
  this->sx2 = oDLTrace.x[1];
  this->sx3 = oDLTrace.x[2];
  this->sx4 = oDLTrace.x[3];
  this->sy1 = oDLTrace.y[0];
  this->sy2 = oDLTrace.y[1];
  this->sy3 = oDLTrace.y[2];
  this->sy4 = oDLTrace.y[3];
  this->sz1 = oDLTrace.z[0];
  this->sz2 = oDLTrace.z[1];
  this->sz3 = oDLTrace.z[2];
  this->sz4 = oDLTrace.z[3];
  this->thickness = oDLTrace.thickness;
}
//=============================================================================
void sstDxf03TypTraceCls::WritToDL(DL_TraceData *poDLTrace)
{
  poDLTrace->x[0] = this->sx1;
  poDLTrace->x[1] = this->sx2;
  poDLTrace->x[2] = this->sx3;
  poDLTrace->x[3] = this->sx4;
  poDLTrace->y[0] = this->sy1;
  poDLTrace->y[1] = this->sy2;
  poDLTrace->y[2] = this->sy3;
  poDLTrace->y[3] = this->sy4;
  poDLTrace->z[0] = this->sz1;
  poDLTrace->z[1] = this->sz2;
  poDLTrace->z[2] = this->sz3;
  poDLTrace->z[3] = this->sz4;
  poDLTrace->thickness = this->thickness;
}
//=============================================================================
// Constructor
sstDxf03FncTraceCls::sstDxf03FncTraceCls():sstDxf03FncBaseCls(sizeof(sstDxf03TypTraceCls))
{
  // this->poDxfArcMem = new sstRec04Cls(sizeof(sstDxf03TypArcCls));
}
//=============================================================================
// Csv Read Function
int sstDxf03FncTraceCls::Csv_Read(int iKey, std::string *sErrTxt, std::string *ssstDxfLib_Str, sstDxf03TypTraceCls *oTrace)
{
  DL_TraceData sDLTrace;
  unsigned long ulTmpArcID = 0;
  unsigned long ulTmpLayerID = 0;
  unsigned long ulTmpBlockID = 0;
  // sstStr01Cls oCsvRow;
  int iStat = 0;
  int iRet  = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  oCsvRow.SetReadPositon(0,0);

  // read base dxf attributes from csv string
  if (iStat >= 0)
    iStat = this->Csv_BaseRead1(0, sErrTxt, ssstDxfLib_Str, oTrace);

  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxfLib_Str, &oTrace->sx1);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxfLib_Str, &oTrace->sy1);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxfLib_Str, &oTrace->sz1);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxfLib_Str, &oTrace->sx2);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxfLib_Str, &oTrace->sy2);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxfLib_Str, &oTrace->sz2);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxfLib_Str, &oTrace->sx3);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxfLib_Str, &oTrace->sy3);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxfLib_Str, &oTrace->sz3);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxfLib_Str, &oTrace->sx4);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxfLib_Str, &oTrace->sy4);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxfLib_Str, &oTrace->sz4);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxfLib_Str, &oTrace->thickness);

  *sErrTxt = oCsvRow.GetErrorString();

  oTrace->ReadFromDL(sDLTrace);

  // osstDxf03TypArcCls->setArcID(ulTmpArcID);
  oTrace->setRecordID(ulTmpArcID);
  oTrace->setLayerID(ulTmpLayerID);
  oTrace->setBlockID(ulTmpBlockID);

  // read base dxf attributes from csv string
  if (iStat >= 0)
    iStat = this->Csv_BaseRead2(0, sErrTxt, ssstDxfLib_Str, oTrace);

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
int sstDxf03FncTraceCls::Csv_Write(int iKey, sstDxf03TypTraceCls *poSstTrace, std::string *ssstDxfLib_Str)
{
  int iStat = 0;

  if ( iKey != 0) return -1;

  ssstDxfLib_Str->clear();

  // write base dxf attributes to csv string
  if (iStat >= 0)
    iStat = this->Csv_BaseWrite1 ( 0, *poSstTrace, ssstDxfLib_Str);

  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, poSstTrace->sx1, ssstDxfLib_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, poSstTrace->sy1, ssstDxfLib_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, poSstTrace->sz1, ssstDxfLib_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, poSstTrace->sx2, ssstDxfLib_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, poSstTrace->sy2, ssstDxfLib_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, poSstTrace->sz2, ssstDxfLib_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, poSstTrace->sx3, ssstDxfLib_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, poSstTrace->sy3, ssstDxfLib_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, poSstTrace->sz3, ssstDxfLib_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, poSstTrace->sx4, ssstDxfLib_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, poSstTrace->sy4, ssstDxfLib_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, poSstTrace->sz4, ssstDxfLib_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, poSstTrace->thickness, ssstDxfLib_Str);

  // write base dxf attributes to csv string
  if (iStat >= 0)
    iStat = this->Csv_BaseWrite2 ( 0, *poSstTrace, ssstDxfLib_Str);

  return iStat;
}
//=============================================================================
int sstDxf03FncTraceCls::Csv_WriteHeader(int iKey, std::string *ssstDxfLib_Str)
{
  std::string oTitelStr;
  int iStat = 0;

//  unsigned long ulLayerID;
//  unsigned long ulBlockID;
//  double cx;
//  double cy;
//  double cz;
//  double radius;
//  double angle1;
//  double angle2;
//  int    color;

  if ( iKey != 0) return -1;

  ssstDxfLib_Str->clear();

  // append base attributes to arc csv titel row
  this->Csv_BaseHeader1 ( 0, ssstDxfLib_Str);

  oTitelStr = "cx";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "cy";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "cz";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "radius";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "angle1";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "angle2";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
//  oTitelStr = "color";
//  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);

  // append base attributes to arc csv titel row
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
int sstDxf03FncTraceCls::ReadCsvFile(int iKey, std::string oFilNam)
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
    sstDxf03TypTraceCls oSstTrace;
    // Read layer object from string row
    iStat = this->Csv_Read( 0, &oErrStr, &oLayStr, &oSstTrace);
    if (iStat < 0)
    {
      iStat1 = -1;
      iStat = -4;
      break;
    }
    // write layer object to recmem
    this->WritNew(0,&oSstTrace,&dRecNo);
    // Read next row from layer csv file
    oLayStr.clear();
    iStat1 = oCsvFilLayer.Rd_StrDS1 ( 2, &oLayStr);
  }

  oCsvFilLayer.fcloseFil(0);

  return iStat;
}
//=============================================================================
int sstDxf03FncTraceCls::WriteCsvFile(int iKey, std::string oDxfFilNam)
{
  sstMisc01AscFilCls oCsvFil;
  std::string oCsvFilNam;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  // ===== Write all Arcs to Csv file
  oCsvFilNam = oDxfFilNam + "_Arc.csv";
  int iStat = oCsvFil.fopenWr(0,(char*) oCsvFilNam.c_str());
  assert(iStat >= 0);

  std::string oCsvStr;

  this->Csv_WriteHeader(0,&oCsvStr);
  oCsvFil.Wr_StrDS1(0, &oCsvStr);

  for(dREC04RECNUMTYP kk = 1; kk <= this->count(); kk++)
  {

    sstDxf03TypTraceCls oDxfTrace;
    iStat = this->Read(0,kk,&oDxfTrace);

    // oDxfArc.setArcID(kk);
    oDxfTrace.setRecordID(kk);

    this->Csv_Write( 0, &oDxfTrace, &oCsvStr);
    oCsvFil.Wr_StrDS1(0, &oCsvStr);
  }

  iStat = oCsvFil.fcloseFil(0);
  return iStat;
}
//=============================================================================
