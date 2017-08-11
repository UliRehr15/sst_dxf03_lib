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
//  sstDxf03Circle.cpp   01.11.16  Re.   06.07.16  Re.
//
//  Functions for Class "sstDxf02Lib"
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

#include "sstDxf03Lib.h"

#include "sstDxf03LibInt.h"

//=============================================================================
// Constructor
sstDxf03TypCircleCls::sstDxf03TypCircleCls()
{
 
}
//=============================================================================
void sstDxf03TypCircleCls::ReadFromDL(const DL_CircleData oDLCircle)
{
  this->cx = oDLCircle.cx;
  this->cy = oDLCircle.cy;
  this->cz = oDLCircle.cz;
  this->radius = oDLCircle.radius;
}
//=============================================================================
void sstDxf03TypCircleCls::WritToDL(DL_CircleData *poDLCircle)
{
  poDLCircle->cx = this->cx;
  poDLCircle->cy = this->cy;
  poDLCircle->cz = this->cz;
  poDLCircle->radius = this->radius;
}
//=============================================================================
double sstDxf03TypCircleCls::getCx() const
{
  return cx;
}
//=============================================================================
void sstDxf03TypCircleCls::setCx(double value)
{
  cx = value;
}
//=============================================================================
double sstDxf03TypCircleCls::getCy() const
{
  return cy;
}
//=============================================================================
void sstDxf03TypCircleCls::setCy(double value)
{
  cy = value;
}
//=============================================================================
double sstDxf03TypCircleCls::getCz() const
{
  return cz;
}
//=============================================================================
void sstDxf03TypCircleCls::setCz(double value)
{
  cz = value;
}
//=============================================================================
double sstDxf03TypCircleCls::getRadius() const
{
  return radius;
}
//=============================================================================
void sstDxf03TypCircleCls::setRadius(double value)
{
  radius = value;
}
//=============================================================================
// // Constructor
sstDxf03FncCircleCls::sstDxf03FncCircleCls():sstDxf03FncBaseCls(sizeof(sstDxf03TypCircleCls))
{
 
}
//=============================================================================
// // Csv Read Function
int sstDxf03FncCircleCls::Csv_Read(int iKey, std::string *sErrTxt, std::string *ssstDxf02_Str, sstDxf03TypCircleCls *osstDxf02TypCircle)
{
  int iStat = 0;
  double dLoc = 0.0;
//  Bloc Function1 Start
//  StrDS1_stru sErrTxt;
  int iRet  = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;
 
  oCsvRow.SetReadPositon(0,0);

  // read base dxf attributes from csv string
  if (iStat >= 0)
    iStat = this->Csv_BaseRead1(0, sErrTxt, ssstDxf02_Str, osstDxf02TypCircle);

  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf02_Str, &dLoc);
      // iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf02_Str, &osstDxf02TypCircle->cx);
  if (iStat >= 0)
  {
    osstDxf02TypCircle->setCx(dLoc);
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf02_Str, &dLoc);
    // iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf02_Str, &osstDxf02TypCircle->cy);
  }
  if (iStat >= 0)
  {
    osstDxf02TypCircle->setCy(dLoc);
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf02_Str, &dLoc);
    // iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf02_Str, &osstDxf02TypCircle->cz);
  }
  if (iStat >= 0)
  {
    osstDxf02TypCircle->setCz(dLoc);
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf02_Str, &dLoc);
    // iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf02_Str, &osstDxf02TypCircle->radius);
  }
  if (iStat >= 0)
  {
    osstDxf02TypCircle->setRadius(dLoc);
  }

  // read base dxf attributes from csv string
  if (iStat >= 0)
    iStat = this->Csv_BaseRead2(0, sErrTxt, ssstDxf02_Str, osstDxf02TypCircle);


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
// // Csv Write Function
int sstDxf03FncCircleCls::Csv_Write(int iKey, sstDxf03TypCircleCls *osstDxf02TypCircle, std::string *ssstDxf02_Str)
{
  int iStat = 0;
//  Bloc Function Write Start
  int iRet  = 0;
  if ( iKey != 0) return -1;

  ssstDxf02_Str->clear();

  // write base dxf attributes to csv string
  if (iStat >= 0)
    iStat = this->Csv_BaseWrite1 ( 0, *osstDxf02TypCircle, ssstDxf02_Str);

  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, osstDxf02TypCircle->getCx(), ssstDxf02_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, osstDxf02TypCircle->getCy(), ssstDxf02_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, osstDxf02TypCircle->getCz(), ssstDxf02_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, osstDxf02TypCircle->getRadius(), ssstDxf02_Str);

  // write base dxf attributes to csv string
  if (iStat >= 0)
    iStat = this->Csv_BaseWrite2 ( 0, *osstDxf02TypCircle, ssstDxf02_Str);

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
int sstDxf03FncCircleCls::Csv_WriteHeader(int iKey, std::string *ssstDxfLib_Str)
{
  std::string oTitelStr;
  int iStat = 0;

//  * sstDxf02;Circle;cx;DD;12;4
//  * sstDxf02;Circle;cy;DD;12;4
//  * sstDxf02;Circle;cz;DD;12;4
//  * sstDxf02;Circle;radius;DD;12;4

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
int sstDxf03FncCircleCls::ReadCsvFile(int iKey, std::string oFilNam)
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
    sstDxf03TypCircleCls oSstArc;
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
int sstDxf03FncCircleCls::WriteCsvFile(int iKey, std::string oDxfFilNam)
{
  sstMisc01AscFilCls oCsvFil;
  std::string oCsvFilNam;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  // ===== Write all Arcs to Csv file
  oCsvFilNam = oDxfFilNam + "_Circle.csv";
  int iStat = oCsvFil.fopenWr(0,(char*) oCsvFilNam.c_str());
  assert(iStat >= 0);

  std::string oCsvStr;

  this->Csv_WriteHeader(0,&oCsvStr);
  oCsvFil.Wr_StrDS1(0, &oCsvStr);

  for(dREC04RECNUMTYP kk = 1; kk <= this->count(); kk++)
  {

    sstDxf03TypCircleCls oDxfArc;
    iStat = this->Read(0,kk,&oDxfArc);

    // oDxfArc.setArcID(kk);
    oDxfArc.setRecordID(kk);

    this->Csv_Write( 0, &oDxfArc, &oCsvStr);
    oCsvFil.Wr_StrDS1(0, &oCsvStr);
  }

  iStat = oCsvFil.fcloseFil(0);
  return iStat;
}
//=============================================================================
