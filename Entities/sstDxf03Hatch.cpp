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
//  sstDxf03Hatch.cpp   01.11.16  Re.   29.04.16  Re.
//
//  Functions for sst Dxf Hatch Classes
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
sstDxf03TypHatchCls::sstDxf03TypHatchCls()
{
  this->angle = 0.0;
  this->numLoops = 0;
  this->originX = 0.0;
  this->originY = 0.0;
  this->dPatternID = 0;
  this->scale = 0.0;
  this->solid = false;
}
//=============================================================================
// Get Number of Class member
unsigned int sstDxf03TypHatchCls::getMemberNumber()
{
  unsigned int uiStat = 0;
  uiStat = 7;
  return uiStat;
}
//=============================================================================
// Get Csv-String with all Class member names
std::string sstDxf03TypHatchCls::getStringName()
{
  std::string oStat;
  oStat = "numLoops;solid;scale;angle;dPatternID;originX;originY";
  return oStat;
}
//=============================================================================
// Get Csv-String with all Class member definition types
std::string sstDxf03TypHatchCls::getStringType()
{
  std::string oStat;
  oStat = "II6.0;BB1.0;DD12.4;DD12.4;UL10.0;DD12.4;DD12.4";
  return oStat;
}
//=============================================================================
// Set Test Data
int sstDxf03TypHatchCls::SetTestData(int iKey)
{
  if ( iKey != 0) return -1;

  this->angle = 1.1;
  this->numLoops = 3;
  this->originX = 2.2;
  this->originY = 3.3;
  this->dPatternID = 6;
  this->scale = 4.4;
  this->solid = true;

  return 0;
}
//=============================================================================
void sstDxf03TypHatchCls::ReadFromDL(const DL_HatchData oDLHatch)
{
  this->angle = oDLHatch.angle;
  this->numLoops = oDLHatch.numLoops;
  this->originX = oDLHatch.originX;
  this->originY = oDLHatch.originY;
  // this->dPatternID = oDLHatch.pattern;
  this->scale = oDLHatch.scale;
  this->solid = oDLHatch.solid;
}
//=============================================================================
void sstDxf03TypHatchCls::WritToDL(DL_HatchData *poDLHatch)
{
  poDLHatch->angle = this->angle;
  poDLHatch->numLoops = this->numLoops;
  poDLHatch->originX = this->originX;
  poDLHatch->originY = this->originY;
  // this->dPatternID = oDLHatch.pattern;
  poDLHatch->scale = this->scale;
  poDLHatch->solid = this->solid;
}
//=============================================================================
int sstDxf03TypHatchCls::getNumLoops() const
{
return numLoops;
}
//=============================================================================
void sstDxf03TypHatchCls::setNumLoops(int value)
{
numLoops = value;
}
//=============================================================================
bool sstDxf03TypHatchCls::getSolid() const
{
return solid;
}
//=============================================================================
void sstDxf03TypHatchCls::setSolid(bool value)
{
solid = value;
}
//=============================================================================
double sstDxf03TypHatchCls::getScale() const
{
return scale;
}
//=============================================================================
void sstDxf03TypHatchCls::setScale(double value)
{
scale = value;
}
//=============================================================================
double sstDxf03TypHatchCls::getAngle() const
{
return angle;
}
//=============================================================================
void sstDxf03TypHatchCls::setAngle(double value)
{
angle = value;
}
//=============================================================================
dREC04RECNUMTYP sstDxf03TypHatchCls::getPatternID() const
{
return dPatternID;
}
//=============================================================================
void sstDxf03TypHatchCls::setPatternID(const dREC04RECNUMTYP &value)
{
dPatternID = value;
}
//=============================================================================
double sstDxf03TypHatchCls::getOriginX() const
{
return originX;
}
//=============================================================================
void sstDxf03TypHatchCls::setOriginX(double value)
{
originX = value;
}
//=============================================================================
double sstDxf03TypHatchCls::getOriginY() const
{
return originY;
}
//=============================================================================
void sstDxf03TypHatchCls::setOriginY(double value)
{
originY = value;
}
//=============================================================================
// Constructor
sstDxf03FncHatchCls::sstDxf03FncHatchCls():sstDxf03FncBaseCls(sizeof(sstDxf03TypHatchCls))
{
  // this->poDxfArcMem = new sstRec04Cls(sizeof(sstDxf03TypHatchCls));
}
//=============================================================================
// Csv Read Function
int sstDxf03FncHatchCls::Csv_Read(int iKey, std::string *sErrTxt, std::string *ssstDxfLib_Str, sstDxf03TypHatchCls *osstDxf02TypHatch)
{
  // dREC04RECNUMTYP dLocRecordID = 0;
  int iLocNumLoops = 0;
  bool bLocSolid = false;
  double dLocScale = 0.0;
  double dLocAngle = 0.0;
  // std::string dPatternID;
  dREC04RECNUMTYP dLocPatternID;  /*! Pattern name. */
  double dLocOriginX = 0.0;
  double dLocOriginY = 0.0;
  int iStat = 0;
  int iRet  = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  oCsvRow.SetReadPositon(0,0);

  //  int numLoops;
  //  bool solid;
  //  double scale;
  //  double angle;
  //  std::string dPatternID;
  //  double originX;
  //  double originY;

  // read base dxf attributes from csv string
  if (iStat >= 0)
    iStat = this->Csv_BaseRead1(0, sErrTxt, ssstDxfLib_Str, osstDxf02TypHatch);

//  if (iStat >= 0) iStat = oCsvRow.CsvString2_UInt4( 0, ssstDxfLib_Str, &dLocRecordID);
//    osstDxf02TypHatch->setRecordID(dLocRecordID);

  if (iStat >= 0) iStat = oCsvRow.CsvString2_Int2( 0, ssstDxfLib_Str, &iLocNumLoops);
  osstDxf02TypHatch->setNumLoops(iLocNumLoops);

  if (iStat >= 0) iStat = oCsvRow.CsvString2_Bool( 0, ssstDxfLib_Str, &bLocSolid);
  osstDxf02TypHatch->setSolid(bLocSolid);

  if (iStat >= 0) iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxfLib_Str, &dLocScale);
  osstDxf02TypHatch->setSolid(dLocScale);

  if (iStat >= 0) iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxfLib_Str, &dLocAngle);
  osstDxf02TypHatch->setAngle(dLocAngle);

  if (iStat >= 0) iStat = oCsvRow.CsvString2_UInt4( 0, ssstDxfLib_Str, &dLocPatternID);
  osstDxf02TypHatch->setPatternID(dLocPatternID);

  if (iStat >= 0) iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxfLib_Str, &dLocOriginX);
  osstDxf02TypHatch->setOriginX(dLocOriginX);

  if (iStat >= 0) iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxfLib_Str, &dLocOriginY);
  osstDxf02TypHatch->setOriginY(dLocOriginY);

  // read base dxf attributes from csv string
  if (iStat >= 0)
    iStat = this->Csv_BaseRead2(0, sErrTxt, ssstDxfLib_Str, osstDxf02TypHatch);


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
int sstDxf03FncHatchCls::Csv_Write(int iKey, sstDxf03TypHatchCls *poSstHatch, std::string *ssstDxfLib_Str)
{
  int iStat = 0;

  if ( iKey != 0) return -1;

  ssstDxfLib_Str->clear();

  // write base dxf attributes to csv string
  if (iStat >= 0)
    iStat = this->Csv_BaseWrite1 ( 0, *poSstHatch, ssstDxfLib_Str);

  // if (iStat >= 0) iStat = oCsvRow.Csv_UInt4_2String( 0, poSstHatch->getRecordID(), ssstDxfLib_Str);
  if (iStat >= 0) iStat = oCsvRow.Csv_Int2_2String( 0, poSstHatch->getNumLoops(), ssstDxfLib_Str);
  if (iStat >= 0) iStat = oCsvRow.Csv_Bool_2String( 0, poSstHatch->getSolid(), ssstDxfLib_Str);
  if (iStat >= 0) iStat = oCsvRow.Csv_Dbl_2String( 0, poSstHatch->getScale(), ssstDxfLib_Str);
  if (iStat >= 0) iStat = oCsvRow.Csv_Dbl_2String( 0, poSstHatch->getAngle(), ssstDxfLib_Str);
  if (iStat >= 0) iStat = oCsvRow.Csv_UInt4_2String( 0, poSstHatch->getPatternID(), ssstDxfLib_Str);
  if (iStat >= 0) iStat = oCsvRow.Csv_Dbl_2String( 0, poSstHatch->getOriginX(), ssstDxfLib_Str);
  if (iStat >= 0) iStat = oCsvRow.Csv_Dbl_2String( 0, poSstHatch->getOriginY(), ssstDxfLib_Str);

  //  int numLoops;
  //  bool solid;
  //  double scale;
  //  double angle;
  //  std::string dPatternID;
  //  double originX;
  //  double originY;

  // write base dxf attributes to csv string
  if (iStat >= 0)
    iStat = this->Csv_BaseWrite2 ( 0, *poSstHatch, ssstDxfLib_Str);

  return iStat;
}
//=============================================================================
int sstDxf03FncHatchCls::Csv_WriteHeader(int iKey, std::string *ssstDxfLib_Str)
{
  std::string oTitelStr;
  int iStat = 0;

  if ( iKey != 0) return -1;

  ssstDxfLib_Str->clear();

  //  int numLoops;
  //  bool solid;
  //  double scale;
  //  double angle;
  //  std::string dPatternID;
  //  double originX;
  //  double originY;

  // append base attributes to hatch csv titel row
  this->Csv_BaseHeader1(0,ssstDxfLib_Str);

  // oTitelStr = "RecordID";
  // iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "NumLoops";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "Solid";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "Scale";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "Angle";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "PatternID";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "OriginX";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "OriginY";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);

  // append base attributes to hatch csv titel row
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
int sstDxf03FncHatchCls::ReadCsvFile(int iKey, std::string oFilNam)
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
    sstDxf03TypHatchCls oSstArc;
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
int sstDxf03FncHatchCls::WriteCsvFile(int iKey, std::string oDxfFilNam)
{
  sstMisc01AscFilCls oCsvFil;
  std::string oCsvFilNam;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  // ===== Write all Insert to Csv file
  oCsvFilNam = oDxfFilNam + "_Hatch.csv";
  int iStat = oCsvFil.fopenWr(0,(char*) oCsvFilNam.c_str());
  assert(iStat >= 0);

  std::string oCsvStr;

  this->Csv_WriteHeader(0,&oCsvStr);
  oCsvFil.Wr_StrDS1(0, &oCsvStr);

  for(dREC04RECNUMTYP kk = 1; kk <= this->count(); kk++)
  {

    sstDxf03TypHatchCls oDxfHatch;
    iStat = this->Read(0,kk,&oDxfHatch);

    oDxfHatch.setRecordID(kk);

    this->Csv_Write( 0, &oDxfHatch, &oCsvStr);
    oCsvFil.Wr_StrDS1(0, &oCsvStr);
  }

  iStat = oCsvFil.fcloseFil(0);
  return iStat;
}
//=============================================================================
