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
//  sstDxf03Line.cpp   13.11.16  Re.     13.11.16  Re.
//
//  Functions for Class "sstDxf03Line"
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

// Constructor
sstDxf03TypLineCls::sstDxf03TypLineCls()
{
 
}
//=============================================================================
void sstDxf03TypLineCls::ReadFromDL(const DL_LineData oDLLine)
{
  this->x1 = oDLLine.x1;
  this->y1 = oDLLine.y1;
  this->z1 = oDLLine.z1;

  this->x2 = oDLLine.x2;
  this->y2 = oDLLine.y2;
  this->z2 = oDLLine.z2;
}
//=============================================================================
void sstDxf03TypLineCls::WritToDL(DL_LineData *poDLLine)
{
  poDLLine->x1 = this->x1;
  poDLLine->y1 = this->y1;
  poDLLine->z1 = this->z1;

  poDLLine->x2 = this->x2;
  poDLLine->y2 = this->y2;
  poDLLine->z2 = this->z2;
}
//=============================================================================
double sstDxf03TypLineCls::getX1() const
{
  return x1;
}
//=============================================================================
void sstDxf03TypLineCls::setX1(double value)
{
  x1 = value;
}
//=============================================================================
double sstDxf03TypLineCls::getY1() const
{
  return y1;
}
//=============================================================================
void sstDxf03TypLineCls::setY1(double value)
{
  y1 = value;
}
//=============================================================================
double sstDxf03TypLineCls::getZ1() const
{
  return z1;
}
//=============================================================================
void sstDxf03TypLineCls::setZ1(double value)
{
  z1 = value;
}
//=============================================================================
double sstDxf03TypLineCls::getX2() const
{
  return x2;
}
//=============================================================================
void sstDxf03TypLineCls::setX2(double value)
{
  x2 = value;
}
//=============================================================================
double sstDxf03TypLineCls::getY2() const
{
  return y2;
}
//=============================================================================
void sstDxf03TypLineCls::setY2(double value)
{
  y2 = value;
}
//=============================================================================
double sstDxf03TypLineCls::getZ2() const
{
  return z2;
}
//=============================================================================
void sstDxf03TypLineCls::setZ2(double value)
{
  z2 = value;
}
//=============================================================================
sstMath01Mbr2Cls sstDxf03TypLineCls::getMbr() const
{
  sstMath01Mbr2Cls oTmpMbr;
  oTmpMbr.Koor2(0,this->getX1(),this->getY1());
  oTmpMbr.Koor2(0,this->getX2(),this->getY2());
  return oTmpMbr;
}
//=============================================================================
// Get Number of Class member
unsigned int sstDxf03TypLineCls::getMemberNumber()
{
  unsigned int uiStat = 0;
  uiStat = 6;
  return uiStat;
}
//=============================================================================
// Function get String of Member Names (csv)
std::string sstDxf03TypLineCls::getStringName()
{
  std::string oStat;
  oStat = "x1;y1;z1;x2;y2;z2";
  return oStat;
}
//=============================================================================
// Function get String of Member Types (csv)
std::string sstDxf03TypLineCls::getStringType()
{
  std::string oStat;
  oStat = "DD12.4;DD12.4;DD12.4;DD12.4;DD12.4;DD12.4";
  return oStat;
}
//=============================================================================
// Constructor
sstDxf03FncLineCls::sstDxf03FncLineCls():sstDxf03FncBaseCls(sizeof(sstDxf03TypLineCls))
{
 
}
//=============================================================================
// Csv Read Function
int sstDxf03FncLineCls::Csv_Read(int iKey, std::string *sErrTxt, std::string *ssstDxf03_Str, sstDxf03TypLineCls *osstDxf03TypLine)
{
  int iStat = 0;
  double dVal = 0.0;
//  Bloc Function1 Start
//  StrDS1_stru sErrTxt;
  int iRet  = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  // read base dxf attributes from csv string
  if (iStat >= 0)
    iStat = this->Csv_BaseRead1(0, sErrTxt, ssstDxf03_Str, osstDxf03TypLine);
 
  if (iStat >= 0)
  {
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf03_Str, &dVal);
  }
  if (iStat >= 0)
  {
    osstDxf03TypLine->setX1(dVal);
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf03_Str, &dVal);
  }
  if (iStat >= 0)
  {
    osstDxf03TypLine->setY1(dVal);
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf03_Str, &dVal);
  }
  if (iStat >= 0)
  {
    osstDxf03TypLine->setZ1(dVal);
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf03_Str, &dVal);
  }
  if (iStat >= 0)
  {
    osstDxf03TypLine->setX2(dVal);
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf03_Str, &dVal);
  }
  if (iStat >= 0)
  {
    osstDxf03TypLine->setY2(dVal);
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf03_Str, &dVal);
  }

  {
    osstDxf03TypLine->setZ2(dVal);
  }

  // read base dxf attributes from csv string
  if (iStat >= 0)
    iStat = this->Csv_BaseRead2(0, sErrTxt, ssstDxf03_Str, osstDxf03TypLine);

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
 
// // Csv Write Function
int sstDxf03FncLineCls::Csv_Write(int iKey, sstDxf03TypLineCls *osstDxf03TypLine, std::string *ssstDxf03_Str)
{
  int iStat = 0;
//  Bloc Function Write Start
  int iRet  = 0;
  if ( iKey != 0) return -1;

  ssstDxf03_Str->clear();

  // write base dxf attributes to csv string
  if (iStat >= 0)
    iStat = this->Csv_BaseWrite1 ( 0, *osstDxf03TypLine, ssstDxf03_Str);
 
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, osstDxf03TypLine->getX1(), ssstDxf03_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, osstDxf03TypLine->getY1(), ssstDxf03_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, osstDxf03TypLine->getZ1(), ssstDxf03_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, osstDxf03TypLine->getX2(), ssstDxf03_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, osstDxf03TypLine->getY2(), ssstDxf03_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, osstDxf03TypLine->getZ2(), ssstDxf03_Str);
 
  // write base dxf attributes to csv string
  if (iStat >= 0)
    iStat = this->Csv_BaseWrite2 ( 0, *osstDxf03TypLine, ssstDxf03_Str);

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
int sstDxf03FncLineCls::Csv_WriteHeader(int iKey, std::string *ssstDxfLib_Str)
{
  std::string oTitelStr;
  int iStat = 0;

  //  double x1;
  //  double y1;
  //  double z1;
  //  double x2;
  //  double y2;
  //  double z2;

  if ( iKey != 0) return -1;

  ssstDxfLib_Str->clear();

  // append base attributes to arc csv titel row
  this->Csv_BaseHeader1 ( 0, ssstDxfLib_Str);

  oTitelStr = "x1";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "y1";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "z1";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "x2";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "y2";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "z2";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);

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
int sstDxf03FncLineCls::ReadCsvFile(int iKey, std::string oFilNam)
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
    sstDxf03TypLineCls oSstLine;
    // Read layer object from string row
    iStat = this->Csv_Read( 0, &oErrStr, &oLayStr, &oSstLine);
    if (iStat < 0)
    {
      iStat1 = -1;
      iStat = -4;
      break;
    }
    // write layer object to recmem
    this->WritNew(0,&oSstLine,&dRecNo);
    // Read next row from layer csv file
    oLayStr.clear();
    iStat1 = oCsvFilLayer.Rd_StrDS1 ( 2, &oLayStr);
  }

  oCsvFilLayer.fcloseFil(0);

  return iStat;
}
//=============================================================================
int sstDxf03FncLineCls::WriteCsvFile(int iKey, std::string oDxfFilNam)
{
  sstMisc01AscFilCls oCsvFil;
  std::string oCsvFilNam;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  // ===== Write all Lines to Csv file
  oCsvFilNam = oDxfFilNam + "_Line.csv";
  int iStat = oCsvFil.fopenWr(0,(char*) oCsvFilNam.c_str());
  assert(iStat >= 0);

  std::string oCsvStr;

  this->Csv_WriteHeader(0,&oCsvStr);
  oCsvFil.Wr_StrDS1(0, &oCsvStr);

  for(dREC04RECNUMTYP kk = 1; kk <= this->count(); kk++)
  {

    sstDxf03TypLineCls oDxfLine;
    iStat = this->Read(0,kk,&oDxfLine);

    // oDxfArc.setArcID(kk);
    oDxfLine.setRecordID(kk);

    this->Csv_Write( 0, &oDxfLine, &oCsvStr);
    oCsvFil.Wr_StrDS1(0, &oCsvStr);
  }

  iStat = oCsvFil.fcloseFil(0);
  return iStat;
}
//=============================================================================
