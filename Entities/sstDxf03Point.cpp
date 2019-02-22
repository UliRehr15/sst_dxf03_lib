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
//  sstDxf03Point.cpp   13.11.16  Re.   13.11.16  Re.
//
//  Functions for Class "sstDxf03Point"
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
sstDxf03TypPointCls::sstDxf03TypPointCls()
{
 
}
//=============================================================================
void sstDxf03TypPointCls::ReadFromDL(const DL_PointData oDLPoint)
{
  this->x = oDLPoint.x;
  this->y = oDLPoint.y;
  this->z = oDLPoint.z;
}
//=============================================================================
void sstDxf03TypPointCls::WritToDL(DL_PointData *poDLPoint)
{
  poDLPoint->x = this->x;
  poDLPoint->y = this->y;
  poDLPoint->z = this->z;
}
//=============================================================================
double sstDxf03TypPointCls::getX() const
{
  return x;
}
//=============================================================================
void sstDxf03TypPointCls::setX(double value)
{
  x = value;
}
//=============================================================================
double sstDxf03TypPointCls::getY() const
{
  return y;
}
//=============================================================================
void sstDxf03TypPointCls::setY(double value)
{
  y = value;
}
//=============================================================================
double sstDxf03TypPointCls::getZ() const
{
  return z;
}
//=============================================================================
void sstDxf03TypPointCls::setZ(double value)
{
  z = value;
}
//=============================================================================
sstMath01Mbr2Cls sstDxf03TypPointCls::getMbr() const
{
  sstMath01Mbr2Cls oTmpMbr;
  oTmpMbr.Koor2(0,this->getX(),this->getY());
  return oTmpMbr;
}
//=============================================================================
// Get Number of Class member
unsigned int sstDxf03TypPointCls::getMemberNumber()
{
  unsigned int uiStat = 0;
  uiStat = 3;
  return uiStat;
}
//=============================================================================
// Function get String of Member Names (csv)
std::string sstDxf03TypPointCls::getStringName()
{
  std::string oStat;
  oStat = "x;y;z";
  return oStat;
}
//=============================================================================
// Function get String of Member Types (csv)
std::string sstDxf03TypPointCls::getStringType()
{
  std::string oStat;
  oStat = "DD12.4;DD12.4;DD12.4";
  return oStat;
}
//=============================================================================
// Constructor
sstDxf03FncPointCls::sstDxf03FncPointCls():sstDxf03FncBaseCls(sizeof(sstDxf03TypPointCls))
{
 
}
 
// // Csv Read Function
int sstDxf03FncPointCls::Csv_Read(int iKey, std::string *sErrTxt, std::string *ssstDxf03_Str, sstDxf03TypPointCls *osstDxf03TypPoint)
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
    iStat = this->Csv_BaseRead1(0, sErrTxt, ssstDxf03_Str, osstDxf03TypPoint);
 
  if (iStat >= 0)
  {
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf03_Str, &dVal);
  }
  if (iStat >= 0)
  {
    osstDxf03TypPoint->setX(dVal);
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf03_Str, &dVal);
  }
  if (iStat >= 0)
  {
    osstDxf03TypPoint->setY(dVal);
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf03_Str, &dVal);
  }

  if (iStat >= 0)
  {
    osstDxf03TypPoint->setZ(dVal);
  }

  // read base dxf attributes from csv string
  if (iStat >= 0)
    iStat = this->Csv_BaseRead2(0, sErrTxt, ssstDxf03_Str, osstDxf03TypPoint);

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
int sstDxf03FncPointCls::Csv_Write(int iKey, sstDxf03TypPointCls *osstDxf03TypPoint, std::string *ssstDxf03_Str)
{
  int iStat = 0;
//  Bloc Function Write Start
  int iRet  = 0;
  if ( iKey != 0) return -1;

  ssstDxf03_Str->clear();

  // write base dxf attributes to csv string
  if (iStat >= 0)
    iStat = this->Csv_BaseWrite1 ( 0, *osstDxf03TypPoint, ssstDxf03_Str);
 
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, osstDxf03TypPoint->getX(), ssstDxf03_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, osstDxf03TypPoint->getY(), ssstDxf03_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, osstDxf03TypPoint->getZ(), ssstDxf03_Str);
 
  // write base dxf attributes to csv string
  if (iStat >= 0)
    iStat = this->Csv_BaseWrite2 ( 0, *osstDxf03TypPoint, ssstDxf03_Str);

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
int sstDxf03FncPointCls::Csv_WriteHeader(int iKey, std::string *ssstDxfLib_Str)
{
  std::string oTitelStr;
  int iStat = 0;

//  double x;
//  double y;
//  double z;

  if ( iKey != 0) return -1;

  ssstDxfLib_Str->clear();

  // append base attributes to arc csv titel row
  this->Csv_BaseHeader1 ( 0, ssstDxfLib_Str);

  oTitelStr = "x";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "y";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "z";
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
int sstDxf03FncPointCls::ReadCsvFile(int iKey, std::string oFilNam)
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
    sstDxf03TypPointCls oSstPoint;
    // Read layer object from string row
    iStat = this->Csv_Read( 0, &oErrStr, &oLayStr, &oSstPoint);
    if (iStat < 0)
    {
      iStat1 = -1;
      iStat = -4;
      break;
    }
    // write layer object to recmem
    this->WritNew(0,&oSstPoint,&dRecNo);
    // Read next row from layer csv file
    oLayStr.clear();
    iStat1 = oCsvFilLayer.Rd_StrDS1 ( 2, &oLayStr);
  }

  oCsvFilLayer.fcloseFil(0);

  return iStat;
}
//=============================================================================
int sstDxf03FncPointCls::WriteCsvFile(int iKey, std::string oDxfFilNam)
{
  sstMisc01AscFilCls oCsvFil;
  std::string oCsvFilNam;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  // ===== Write all Points to Csv file
  oCsvFilNam = oDxfFilNam + "_Point.csv";
  int iStat = oCsvFil.fopenWr(0,(char*) oCsvFilNam.c_str());
  assert(iStat >= 0);

  std::string oCsvStr;

  this->Csv_WriteHeader(0,&oCsvStr);
  oCsvFil.Wr_StrDS1(0, &oCsvStr);

  for(dREC04RECNUMTYP kk = 1; kk <= this->count(); kk++)
  {

    sstDxf03TypPointCls oDxfPoint;
    iStat = this->Read(0,kk,&oDxfPoint);

    // oDxfArc.setArcID(kk);
    oDxfPoint.setRecordID(kk);

    this->Csv_Write( 0, &oDxfPoint, &oCsvStr);
    oCsvFil.Wr_StrDS1(0, &oCsvStr);
  }

  iStat = oCsvFil.fcloseFil(0);
  return iStat;
}
//=============================================================================
