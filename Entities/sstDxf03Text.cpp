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
//  sstDxf03Text.cpp   01.11.16  Re.   06.07.16  Re.
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
#include <sstDxf03Lib.h>

#include "sstDxf03LibInt.h"
 
//=============================================================================
// Constructor
sstDxf03TypTextCls::sstDxf03TypTextCls()
{
  memset( this->text, 0, 100);
}
//=============================================================================
sstMath01Mbr2Cls sstDxf03TypTextCls::getMbr() const
{
  sstMath01Mbr2Cls oTmpMbr;
  // oTmpMbr.Koor2(0,this->getX(),this->getY());
  oTmpMbr.Koor2(0,this->getIpx(),this->getIpy());
  return oTmpMbr;
}
//=============================================================================
// Get Number of Class member
unsigned int sstDxf03TypTextCls::getMemberNumber()
{
  unsigned int uiStat = 0;
  uiStat = 14;
  return uiStat;
}
//=============================================================================
// Get Csv-String with all Class member names
std::string sstDxf03TypTextCls::getStringName()
{
  std::string oStat;
  oStat = "ipx;ipy;ipz;apx;apy;apz;height;xScaleFactor;textGenerationFlags;hJustification;vJustification;text;style_ID;angle";
  return oStat;
}
//=============================================================================
// Get Csv-String with all Class member definition types
std::string sstDxf03TypTextCls::getStringType()
{
  std::string oStat;
  oStat = "DD12.4;DD12.4;DD12.4;DD12.4;DD12.4;DD12.4;DD12.4;DD12.4;II6.0;II6.0;II6.0;CC100.0;UL10.0;DD12.4";
  return oStat;
}
//=============================================================================
void sstDxf03TypTextCls::ReadFromDL(const DL_TextData oDLText)
{
  this->ipx = oDLText.ipx;  // * sstDxf02;Text;ipx;DD;12;4
  this->ipy = oDLText.ipy;  // DD;12;4
  this->ipz = oDLText.ipz;  // DD;12;4
  this->apx = oDLText.apx;  // DD;12;4
  this->apy = oDLText.apy;  // DD;12;4
  this->apz = oDLText.apz;  // DD;12;4
  this->height = oDLText.height;  // DD;12;4
  this->xScaleFactor = oDLText.xScaleFactor;  // DD;12;4
  this->textGenerationFlags = oDLText.textGenerationFlags;  // II;6;0
  this->hJustification = oDLText.hJustification;  // II;6;0
  this->vJustification = oDLText.vJustification;  // II;6;0
  strncpy(this->text, oDLText.text.c_str(), 100);  // CC;100;0
  // this->style_ID = oDLText.style;  // UL;10;0
  this->style_ID = 1;  // UL;10;0
  this->angle = oDLText.angle;  // DD;12;4
}
//=============================================================================
void sstDxf03TypTextCls::WritToDL(DL_TextData *poDLText)
{
  poDLText->ipx = this->ipx;  // DD;12;4
  poDLText->ipy = this->ipy;  // DD;12;4
  poDLText->ipz = this->ipz;  // ->;DD;12;4
  poDLText->apx = this->apx;  // ->;DD;12;4
  poDLText->apy = this->apy;  // ->;DD;12;4
  poDLText->apz = this->apz;  // ->;DD;12;4
  poDLText->height = this->height;  // ->;DD;12;4
  poDLText->xScaleFactor = this->xScaleFactor;  //  ->;DD;12;4
  poDLText->textGenerationFlags = this->textGenerationFlags;  // ->;II;6;0
  poDLText->hJustification = this->hJustification;  // ->;II;6;0
  poDLText->vJustification = this->vJustification;  // ->;II;6;0
  poDLText->text = this->text;  //  ->;CC;100;0
  // poDLText->style = this->style_ID;  // ->;UL;10;0
  poDLText->style = "standard";  // ->;UL;10;0
  poDLText->angle = this->angle;  //  ->;DD;12;4
}
//=============================================================================
double sstDxf03TypTextCls::getIpx() const
{
return ipx;
}
//=============================================================================
void sstDxf03TypTextCls::setIpx(double value)
{
ipx = value;
}
//=============================================================================
double sstDxf03TypTextCls::getIpy() const
{
return ipy;
}
//=============================================================================
void sstDxf03TypTextCls::setIpy(double value)
{
ipy = value;
}
//=============================================================================
double sstDxf03TypTextCls::getIpz() const
{
return ipz;
}
//=============================================================================
void sstDxf03TypTextCls::setIpz(double value)
{
ipz = value;
}
//=============================================================================
double sstDxf03TypTextCls::getApx() const
{
return apx;
}
//=============================================================================
void sstDxf03TypTextCls::setApx(double value)
{
apx = value;
}
//=============================================================================
double sstDxf03TypTextCls::getApy() const
{
return apy;
}
//=============================================================================
void sstDxf03TypTextCls::setApy(double value)
{
apy = value;
}
//=============================================================================
double sstDxf03TypTextCls::getApz() const
{
return apz;
}
//=============================================================================
void sstDxf03TypTextCls::setApz(double value)
{
apz = value;
}
//=============================================================================
double sstDxf03TypTextCls::getHeight() const
{
return height;
}
//=============================================================================
void sstDxf03TypTextCls::setHeight(double value)
{
height = value;
}
//=============================================================================
double sstDxf03TypTextCls::getXScaleFactor() const
{
return xScaleFactor;
}
//=============================================================================
void sstDxf03TypTextCls::setXScaleFactor(double value)
{
xScaleFactor = value;
}
//=============================================================================
int sstDxf03TypTextCls::getTextGenerationFlags() const
{
return textGenerationFlags;
}
//=============================================================================
void sstDxf03TypTextCls::setTextGenerationFlags(int value)
{
textGenerationFlags = value;
}
//=============================================================================
int sstDxf03TypTextCls::getHJustification() const
{
return hJustification;
}
//=============================================================================
void sstDxf03TypTextCls::setHJustification(int value)
{
hJustification = value;
}
//=============================================================================
int sstDxf03TypTextCls::getVJustification() const
{
return vJustification;
}
//=============================================================================
void sstDxf03TypTextCls::setVJustification(int value)
{
vJustification = value;
}
//=============================================================================
std::string sstDxf03TypTextCls::getText() const
{
return this->text;
}
//=============================================================================
void sstDxf03TypTextCls::setText(std::string value)
{
  strncpy(this->text,value.c_str(),101);
}
//=============================================================================
unsigned long sstDxf03TypTextCls::getStyle_ID() const
{
return style_ID;
}
//=============================================================================
void sstDxf03TypTextCls::setStyle_ID(unsigned long value)
{
style_ID = value;
}
//=============================================================================
double sstDxf03TypTextCls::getAngle() const
{
return angle;
}
//=============================================================================
void sstDxf03TypTextCls::setAngle(double value)
{
angle = value;
}
//=============================================================================
// // Constructor
sstDxf03FncTextCls::sstDxf03FncTextCls():sstDxf03FncBaseCls(sizeof(sstDxf03TypTextCls))
{
 
}
 
// // Csv Read Function
int sstDxf03FncTextCls::Csv_Read(int iKey, std::string *sErrTxt, std::string *ssstDxf02_Str, sstDxf03TypTextCls *osstDxf02TypText)
{
  int iStat = 0;
  double dVal = 0.0;
  int iVal = 0;
  unsigned long ulVal = 0;
  std::string sVal;
//  Bloc Function1 Start
//  StrDS1_stru sErrTxt;
  int iRet  = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;
 
  oCsvRow.SetReadPositon(0,0);

  // read base dxf attributes from csv string
  if (iStat >= 0)
    iStat = this->Csv_BaseRead1(0, sErrTxt, ssstDxf02_Str, osstDxf02TypText);

  if (iStat >= 0)
  {
    // iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf02_Str, &osstDxf02TypText->ipx);
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf02_Str, &dVal);
  }
  if (iStat >= 0)
  {
    // iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf02_Str, &osstDxf02TypText->ipy);
    osstDxf02TypText->setIpx(dVal);
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf02_Str, &dVal);
  }
  if (iStat >= 0)
  {
    // iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf02_Str, &osstDxf02TypText->ipz);
    osstDxf02TypText->setIpy(dVal);
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf02_Str, &dVal);
  }
  if (iStat >= 0)
  {
    // iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf02_Str, &osstDxf02TypText->apx);
    osstDxf02TypText->setIpz(dVal);
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf02_Str, &dVal);
  }
  if (iStat >= 0)
  {
    // iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf02_Str, &osstDxf02TypText->apy);
    osstDxf02TypText->setApx(dVal);
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf02_Str, &dVal);
  }
  if (iStat >= 0)
  {
    // iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf02_Str, &osstDxf02TypText->apz);
    osstDxf02TypText->setApy(dVal);
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf02_Str, &dVal);
  }
  if (iStat >= 0)
  {
    // iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf02_Str, &osstDxf02TypText->height);
    osstDxf02TypText->setApz(dVal);
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf02_Str, &dVal);
  }
  if (iStat >= 0)
  {
    // iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf02_Str, &osstDxf02TypText->xScaleFactor);
    osstDxf02TypText->setHeight(dVal);
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf02_Str, &dVal);
  }
  if (iStat >= 0)
  {
    // iStat = oCsvRow.CsvString2_Int2( 0, ssstDxf02_Str, &osstDxf02TypText->textGenerationFlags);
    osstDxf02TypText->setXScaleFactor(dVal);
    iStat = oCsvRow.CsvString2_Int2( 0, ssstDxf02_Str, &iVal);
  }
  if (iStat >= 0)
  {
    // iStat = oCsvRow.CsvString2_Int2( 0, ssstDxf02_Str, &osstDxf02TypText->hJustification);
    osstDxf02TypText->setTextGenerationFlags(iVal);
    iStat = oCsvRow.CsvString2_Int2( 0, ssstDxf02_Str, &iVal);
  }
  if (iStat >= 0)
  {
    // iStat = oCsvRow.CsvString2_Int2( 0, ssstDxf02_Str, &osstDxf02TypText->vJustification);
    osstDxf02TypText->setHJustification(iVal);
    iStat = oCsvRow.CsvString2_Int2( 0, ssstDxf02_Str, &iVal);
  }
  if (iStat >= 0)
  {
    // iStat = oCsvRow.CsvString2_Char( 0, ssstDxf02_Str, osstDxf02TypText->text,101);
    osstDxf02TypText->setVJustification(iVal);
    iStat = oCsvRow.CsvString2_Str( 0, ssstDxf02_Str, &sVal);
  }
  if (iStat >= 0)
  {
    // iStat = oCsvRow.CsvString2_UInt4( 0, ssstDxf02_Str, &osstDxf02TypText->style_ID);
    osstDxf02TypText->setText(sVal);
    iStat = oCsvRow.CsvString2_UInt4( 0, ssstDxf02_Str, &ulVal);
  }
  if (iStat >= 0)
  {
    // iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf02_Str, &osstDxf02TypText->angle);
    osstDxf02TypText->setStyle_ID(ulVal);
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf02_Str, &dVal);
  }
  if (iStat >= 0)
  {
    osstDxf02TypText->setAngle(dVal);
  }

  // read base dxf attributes from csv string
  if (iStat >= 0)
    iStat = this->Csv_BaseRead2(0, sErrTxt, ssstDxf02_Str, osstDxf02TypText);
 
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
int sstDxf03FncTextCls::Csv_Write(int iKey, sstDxf03TypTextCls *osstDxf02TypText, std::string *ssstDxf02_Str)
{
  int iStat = 0;
//  Bloc Function Write Start
  int iRet  = 0;
  if ( iKey != 0) return -1;
  ssstDxf02_Str->clear();

  // write base dxf attributes to csv string
  if (iStat >= 0)
    iStat = this->Csv_BaseWrite1 ( 0, *osstDxf02TypText, ssstDxf02_Str);

  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, osstDxf02TypText->getIpx(), ssstDxf02_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, osstDxf02TypText->getIpy(), ssstDxf02_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, osstDxf02TypText->getIpz(), ssstDxf02_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, osstDxf02TypText->getApx(), ssstDxf02_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, osstDxf02TypText->getApy(), ssstDxf02_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, osstDxf02TypText->getApz(), ssstDxf02_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, osstDxf02TypText->getHeight(), ssstDxf02_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, osstDxf02TypText->getXScaleFactor(), ssstDxf02_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Int2_2String ( 0, osstDxf02TypText->getTextGenerationFlags(), ssstDxf02_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Int2_2String ( 0, osstDxf02TypText->getHJustification(), ssstDxf02_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Int2_2String ( 0, osstDxf02TypText->getVJustification(), ssstDxf02_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Str_2String ( 0, osstDxf02TypText->getText(), ssstDxf02_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_UInt4_2String ( 0, osstDxf02TypText->getStyle_ID(), ssstDxf02_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, osstDxf02TypText->getAngle(), ssstDxf02_Str);

  // write base dxf attributes to csv string
  if (iStat >= 0)
    iStat = this->Csv_BaseWrite2 ( 0, *osstDxf02TypText, ssstDxf02_Str);

 
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
int sstDxf03FncTextCls::Csv_WriteHeader(int iKey, std::string *ssstDxfLib_Str)
{
  std::string oTitelStr;
  int iStat = 0;


  if ( iKey != 0) return -1;

  ssstDxfLib_Str->clear();

  // append base attributes to arc csv titel row
  this->Csv_BaseHeader1 ( 0, ssstDxfLib_Str);

  //  * sstDxf02;Text;ipx;DD;12;4
  //  * sstDxf02;Text;ipy;DD;12;4
  //  * sstDxf02;Text;ipz;DD;12;4

  oTitelStr = "ipx";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "ipy";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "ipz";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);

  //  * sstDxf02;Text;apx;DD;12;4
  //  * sstDxf02;Text;apy;DD;12;4
  //  * sstDxf02;Text;apz;DD;12;4

  oTitelStr = "apx";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "apy";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "apz";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);

  //  * sstDxf02;Text;height;DD;12;4
  //  * sstDxf02;Text;xScaleFactor;DD;12;4
  //  * sstDxf02;Text;textGenerationFlags;II;6;0

  oTitelStr = "heigth";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "xScaleFactor";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "textGenerationFlags";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);

  //  * sstDxf02;Text;hJustification;II;6;0
  //  * sstDxf02;Text;vJustification;II;6;0

  oTitelStr = "hJustification";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "vJustification";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);

  //  * sstDxf02;Text;text;CC;100;0
  //  * sstDxf02;Text;style_ID;UL;10;0
  //  * sstDxf02;Text;angle;DD;12;4
  oTitelStr = "text";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "style_ID";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "angle";
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
int sstDxf03FncTextCls::ReadCsvFile(int iKey, std::string oFilNam)
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
    sstDxf03TypTextCls oSstText;
    // Read layer object from string row
    iStat = this->Csv_Read( 0, &oErrStr, &oLayStr, &oSstText);
    if (iStat < 0)
    {
      iStat1 = -1;
      iStat = -4;
      break;
    }
    // write layer object to recmem
    this->WritNew(0,&oSstText,&dRecNo);
    // Read next row from layer csv file
    oLayStr.clear();
    iStat1 = oCsvFilLayer.Rd_StrDS1 ( 2, &oLayStr);
  }

  oCsvFilLayer.fcloseFil(0);

  return iStat;
}
//=============================================================================
int sstDxf03FncTextCls::WriteCsvFile(int iKey, std::string oDxfFilNam)
{
  sstMisc01AscFilCls oCsvFil;
  std::string oCsvFilNam;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  // ===== Write all Arcs to Csv file
  oCsvFilNam = oDxfFilNam + "_Text.csv";
  int iStat = oCsvFil.fopenWr(0,(char*) oCsvFilNam.c_str());
  assert(iStat >= 0);

  std::string oCsvStr;

  this->Csv_WriteHeader(0,&oCsvStr);
  oCsvFil.Wr_StrDS1(0, &oCsvStr);

  for(dREC04RECNUMTYP kk = 1; kk <= this->count(); kk++)
  {

    sstDxf03TypTextCls oDxfText;
    iStat = this->Read(0,kk,&oDxfText);

    // oDxfArc.setArcID(kk);
    oDxfText.setRecordID(kk);

    this->Csv_Write( 0, &oDxfText, &oCsvStr);
    oCsvFil.Wr_StrDS1(0, &oCsvStr);
  }

  iStat = oCsvFil.fcloseFil(0);
  return iStat;
}
//=============================================================================

