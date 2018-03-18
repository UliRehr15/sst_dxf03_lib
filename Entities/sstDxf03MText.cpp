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
//  sstDxf03MText.cpp   01.11.16  Re.   06.07.16  Re.
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

// Constructor
sstDxf03TypMTextCls::sstDxf03TypMTextCls()
{
 
}
//=============================================================================
void sstDxf03TypMTextCls::ReadFromDL(const DL_MTextData oDLMText)
{
  this->ipx = oDLMText.ipx;  // * sstDxf02;MText;ipx;DD;12;4
  this->ipy = oDLMText.ipy;  // .;DD;12;4
  this->ipz = oDLMText.ipz;  // .;DD;12;4
  this->dirx = oDLMText.dirx;  // .;DD;12;4
  this->diry = oDLMText.diry;  // .;DD;12;4
  this->dirz = oDLMText.dirz;  // .;DD;12;4
  this->height = oDLMText.height;  // .;DD;12;4
  this->width = oDLMText.width;  // .;DD;12;4
  this->attachmentPoint = oDLMText.attachmentPoint;  // .;II;6;0
  this->drawingDirection = oDLMText.drawingDirection;  // .;II;6;0
  this->lineSpacingStyle = oDLMText.lineSpacingStyle;;  // .;II;6;0
  this->lineSpacingFactor = oDLMText.lineSpacingFactor;  // .;DD;12;4
  // this->text = oDLMText.text;  // .;CC;100;0
  strncpy(this->text,oDLMText.text.c_str(),100);  // .;CC;100;0
  // this->style_ID = oDLMText.style;  // .;UL;10;0
  this->style_ID = 1;  // .;UL;10;0
  this->angle = oDLMText.angle;  // .;DD;12;4
}
//=============================================================================
void sstDxf03TypMTextCls::WritToDL(DL_MTextData *poDLMText)
{
  poDLMText->ipx = this->ipx;  // DD;12;4
  poDLMText->ipy = this->ipy;  // ->;DD;12;4
  poDLMText->ipz = this->ipz;  // ->;DD;12;4
  poDLMText->dirx = this->dirx;  // ->;DD;12;4
  poDLMText->diry = this->diry;  // ->;DD;12;4
  poDLMText->dirz = this->dirz;  // ->;DD;12;4
  poDLMText->height = this->height;  // ->;DD;12;4
  poDLMText->width = this->width;  // ->;DD;12;4
  poDLMText->attachmentPoint = this->attachmentPoint;  // ->;II;6;0
  poDLMText->drawingDirection = this->drawingDirection;  // ->;II;6;0
  poDLMText->lineSpacingStyle = this->lineSpacingStyle;  // ->;II;6;0
  poDLMText->lineSpacingFactor = this->lineSpacingFactor;  // ->;DD;12;4
  poDLMText->text = this->text;  // >;CC;100;0
  // poDLMText->style_ID = this->style_ID;  // ->;UL;10;0
  poDLMText->style = "standard";  // ->;UL;10;0
  poDLMText->angle = this->angle;  // ->;DD;12;4
}
//=============================================================================
double sstDxf03TypMTextCls::getIpx() const
{
return ipx;
}
//=============================================================================
void sstDxf03TypMTextCls::setIpx(double value)
{
ipx = value;
}
//=============================================================================
double sstDxf03TypMTextCls::getIpy() const
{
return ipy;
}
//=============================================================================
void sstDxf03TypMTextCls::setIpy(double value)
{
ipy = value;
}
//=============================================================================
double sstDxf03TypMTextCls::getIpz() const
{
return ipz;
}
//=============================================================================
void sstDxf03TypMTextCls::setIpz(double value)
{
ipz = value;
}
//=============================================================================
double sstDxf03TypMTextCls::getDirx() const
{
return dirx;
}
//=============================================================================
void sstDxf03TypMTextCls::setDirx(double value)
{
dirx = value;
}
//=============================================================================
double sstDxf03TypMTextCls::getDiry() const
{
return diry;
}
//=============================================================================
void sstDxf03TypMTextCls::setDiry(double value)
{
diry = value;
}
//=============================================================================
double sstDxf03TypMTextCls::getDirz() const
{
return dirz;
}
//=============================================================================
void sstDxf03TypMTextCls::setDirz(double value)
{
dirz = value;
}
//=============================================================================
double sstDxf03TypMTextCls::getHeight() const
{
return height;
}
//=============================================================================
void sstDxf03TypMTextCls::setHeight(double value)
{
height = value;
}
//=============================================================================
double sstDxf03TypMTextCls::getWidth() const
{
return width;
}
//=============================================================================
void sstDxf03TypMTextCls::setWidth(double value)
{
width = value;
}
//=============================================================================
int sstDxf03TypMTextCls::getAttachmentPoint() const
{
return attachmentPoint;
}
//=============================================================================
void sstDxf03TypMTextCls::setAttachmentPoint(int value)
{
attachmentPoint = value;
}
//=============================================================================
int sstDxf03TypMTextCls::getDrawingDirection() const
{
return drawingDirection;
}
//=============================================================================
void sstDxf03TypMTextCls::setDrawingDirection(int value)
{
drawingDirection = value;
}
//=============================================================================
int sstDxf03TypMTextCls::getLineSpacingStyle() const
{
return lineSpacingStyle;
}
//=============================================================================
void sstDxf03TypMTextCls::setLineSpacingStyle(int value)
{
lineSpacingStyle = value;
}
//=============================================================================
double sstDxf03TypMTextCls::getLineSpacingFactor() const
{
return lineSpacingFactor;
}
//=============================================================================
void sstDxf03TypMTextCls::setLineSpacingFactor(double value)
{
lineSpacingFactor = value;
}
//=============================================================================
std::string sstDxf03TypMTextCls::getText() const
{
return this->text;
}
//=============================================================================
void sstDxf03TypMTextCls::setText(std::string value)
{
  strncpy(this->text,value.c_str(),101);
}
//=============================================================================
unsigned long sstDxf03TypMTextCls::getStyle_ID() const
{
return style_ID;
}
//=============================================================================
void sstDxf03TypMTextCls::setStyle_ID(unsigned long value)
{
style_ID = value;
}
//=============================================================================
double sstDxf03TypMTextCls::getAngle() const
{
return angle;
}
//=============================================================================
void sstDxf03TypMTextCls::setAngle(double value)
{
angle = value;
}
//=============================================================================
// Get Number of Class member
unsigned int sstDxf03TypMTextCls::getMemberNumber()
{
  unsigned int uiStat = 0;
  uiStat = 15;
  return uiStat;
}
//=============================================================================
// Function get String of Member Names (csv)
std::string sstDxf03TypMTextCls::getStringName()
{
  std::string oStat;
  oStat = "ipx;ipy;ipz;dirx;diry;dirz;height;width;attachmentPoint;drawingDirection;lineSpacingStyle;lineSpacingFactor;text;style_ID;angle";
  return oStat;
}
//=============================================================================
// Function get String of Member Types (csv)
std::string sstDxf03TypMTextCls::getStringType()
{
  std::string oStat;
  oStat = "DD12.4;DD12.4;DD12.4;DD12.4;DD12.4;DD12.4;DD12.4;DD12.4;II6.0;II6.0;II6.0;DD12.4;CC100.0;UL10.0;DD12.4";
  return oStat;
}
//=============================================================================
// Constructor
sstDxf03FncMTextCls::sstDxf03FncMTextCls():sstDxf03FncBaseCls(sizeof(sstDxf03TypMTextCls))
{
 
}
//=============================================================================
// // Csv Read Function
int sstDxf03FncMTextCls::Csv_Read(int iKey, std::string *sErrTxt, std::string *ssstDxf02_Str, sstDxf03TypMTextCls *osstDxf02TypMText)
{
  double dVal = 0.0;
  int iVal = 0;
  std::string sVal;
  unsigned long ulVal = 0;
  int iStat = 0;
//  Bloc Function1 Start
//  StrDS1_stru sErrTxt;
  int iRet  = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;
 
  oCsvRow.SetReadPositon(0,0);

  // read base dxf attributes from csv string
  if (iStat >= 0)
    iStat = this->Csv_BaseRead1(0, sErrTxt, ssstDxf02_Str, osstDxf02TypMText);

  if (iStat >= 0)
  {
    // iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf02_Str, &osstDxf02TypMText->ipx);
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf02_Str, &dVal);
  }
  if (iStat >= 0)
  {
    // iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf02_Str, &osstDxf02TypMText->ipy);
    osstDxf02TypMText->setIpx(dVal);
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf02_Str, &dVal);
  }
  if (iStat >= 0)
  {
    // iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf02_Str, &osstDxf02TypMText->ipz);
    osstDxf02TypMText->setIpy(dVal);
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf02_Str, &dVal);
  }
  if (iStat >= 0)
  {
    // iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf02_Str, &osstDxf02TypMText->dirx);
    osstDxf02TypMText->setIpz(dVal);
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf02_Str, &dVal);
  }
  if (iStat >= 0)
  {
    // iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf02_Str, &osstDxf02TypMText->diry);
    osstDxf02TypMText->setDirx(dVal);
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf02_Str, &dVal);
  }
  if (iStat >= 0)
  {
    // iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf02_Str, &osstDxf02TypMText->dirz);
    osstDxf02TypMText->setDiry(dVal);
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf02_Str, &dVal);
  }
  if (iStat >= 0)
  {
    // iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf02_Str, &osstDxf02TypMText->height);
    osstDxf02TypMText->setDirz(dVal);
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf02_Str, &dVal);
  }
  if (iStat >= 0)
  {
    // iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf02_Str, &osstDxf02TypMText->width);
    osstDxf02TypMText->setHeight(dVal);
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf02_Str, &dVal);
  }
  if (iStat >= 0)
  {
    // iStat = oCsvRow.CsvString2_Int2( 0, ssstDxf02_Str, &osstDxf02TypMText->attachmentPoint);
    osstDxf02TypMText->setWidth(dVal);
    iStat = oCsvRow.CsvString2_Int2( 0, ssstDxf02_Str, &iVal);
  }
  if (iStat >= 0)
  {
    // iStat = oCsvRow.CsvString2_Int2( 0, ssstDxf02_Str, &osstDxf02TypMText->drawingDirection);
    osstDxf02TypMText->setAttachmentPoint(iVal);
    iStat = oCsvRow.CsvString2_Int2( 0, ssstDxf02_Str, &iVal);
  }
  if (iStat >= 0)
  {
    // iStat = oCsvRow.CsvString2_Int2( 0, ssstDxf02_Str, &osstDxf02TypMText->lineSpacingStyle);
    osstDxf02TypMText->setDrawingDirection(iVal);
    iStat = oCsvRow.CsvString2_Int2( 0, ssstDxf02_Str, &iVal);
  }
  if (iStat >= 0)
  {
    // iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf02_Str, &osstDxf02TypMText->lineSpacingFactor);
    osstDxf02TypMText->setLineSpacingStyle(iVal);
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf02_Str, &dVal);
  }
  if (iStat >= 0)
  {
    // iStat = oCsvRow.CsvString2_Char( 0, ssstDxf02_Str, osstDxf02TypMText->text,101);
    osstDxf02TypMText->setLineSpacingFactor(dVal);
    iStat = oCsvRow.CsvString2_Str( 0, ssstDxf02_Str, &sVal);
  }
  if (iStat >= 0)
  {
    // iStat = oCsvRow.CsvString2_UInt4( 0, ssstDxf02_Str, &osstDxf02TypMText->style_ID);
    osstDxf02TypMText->setText(sVal);
    iStat = oCsvRow.CsvString2_UInt4( 0, ssstDxf02_Str, &ulVal);
  }
  if (iStat >= 0)
  {
    // iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf02_Str, &osstDxf02TypMText->angle);
    osstDxf02TypMText->setStyle_ID(ulVal);
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf02_Str, &dVal);
  }
  if (iStat >= 0)
  {
    // iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf02_Str, &osstDxf02TypMText->angle);
    osstDxf02TypMText->setAngle(dVal);
  }

  // read base dxf attributes from csv string
  if (iStat >= 0)
    iStat = this->Csv_BaseRead2(0, sErrTxt, ssstDxf02_Str, osstDxf02TypMText);


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
int sstDxf03FncMTextCls::Csv_Write(int iKey, sstDxf03TypMTextCls *osstDxf02TypMText, std::string *ssstDxf02_Str)
{
  int iStat = 0;
//  Bloc Function Write Start
  int iRet  = 0;
  if ( iKey != 0) return -1;
  ssstDxf02_Str->clear();

  // write base dxf attributes to csv string
  if (iStat >= 0)
    iStat = this->Csv_BaseWrite1 ( 0, *osstDxf02TypMText, ssstDxf02_Str);

 
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, osstDxf02TypMText->getIpx(), ssstDxf02_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, osstDxf02TypMText->getIpy(), ssstDxf02_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, osstDxf02TypMText->getIpz(), ssstDxf02_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, osstDxf02TypMText->getDirx(), ssstDxf02_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, osstDxf02TypMText->getDiry(), ssstDxf02_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, osstDxf02TypMText->getDirz(), ssstDxf02_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, osstDxf02TypMText->getHeight(), ssstDxf02_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, osstDxf02TypMText->getWidth(), ssstDxf02_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Int2_2String ( 0, osstDxf02TypMText->getAttachmentPoint(), ssstDxf02_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Int2_2String ( 0, osstDxf02TypMText->getDrawingDirection(), ssstDxf02_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Int2_2String ( 0, osstDxf02TypMText->getLineSpacingStyle(), ssstDxf02_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, osstDxf02TypMText->getLineSpacingFactor(), ssstDxf02_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Str_2String ( 0, osstDxf02TypMText->getText(), ssstDxf02_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_UInt4_2String ( 0, osstDxf02TypMText->getStyle_ID(), ssstDxf02_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, osstDxf02TypMText->getAngle(), ssstDxf02_Str);

  // write base dxf attributes to csv string
  if (iStat >= 0)
    iStat = this->Csv_BaseWrite2 ( 0, *osstDxf02TypMText, ssstDxf02_Str);

 
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
int sstDxf03FncMTextCls::Csv_WriteHeader(int iKey, std::string *ssstDxfLib_Str)
{
  std::string oTitelStr;
  int iStat = 0;



  if ( iKey != 0) return -1;

  ssstDxfLib_Str->clear();

  // append base attributes to arc csv titel row
  this->Csv_BaseHeader1 ( 0, ssstDxfLib_Str);

  //  * sstDxf02;MText;ipx;DD;12;4
  //  * sstDxf02;MText;ipy;DD;12;4
  //  * sstDxf02;MText;ipz;DD;12;4

  oTitelStr = "ipx";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "ipy";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "ipz";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);

  //  * sstDxf02;MText;dirx;DD;12;4
  //  * sstDxf02;MText;diry;DD;12;4
  //  * sstDxf02;MText;dirz;DD;12;4

  oTitelStr = "dirx";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "diry";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "dirz";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);

  //  * sstDxf02;MText;height;DD;12;4
  //  * sstDxf02;MText;width;DD;12;4

  oTitelStr = "height";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "width";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);

  //  * sstDxf02;MText;attachmentPoint;II;6;0
  //  * sstDxf02;MText;drawingDirection;II;6;0
  //  * sstDxf02;MText;lineSpacingStyle;II;6;0
  //  * sstDxf02;MText;lineSpacingFactor;DD;12;4

  oTitelStr = "attachmentPoint";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "drawingDirection";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "lineSpacingStyle";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "lineSpacingFactor";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);

  //  * sstDxf02;MText;text;CC;100;0
  //  * sstDxf02;MText;style_ID;UL;10;0
  //  * sstDxf02;MText;angle;DD;12;4

  oTitelStr = "text";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "stype_ID";
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
//=============================================================================
int sstDxf03FncMTextCls::ReadCsvFile(int iKey, std::string oFilNam)
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
    sstDxf03TypMTextCls oSstMText;
    // Read layer object from string row
    iStat = this->Csv_Read( 0, &oErrStr, &oLayStr, &oSstMText);
    if (iStat < 0)
    {
      iStat1 = -1;
      iStat = -4;
      break;
    }
    // write layer object to recmem
    this->WritNew(0,&oSstMText,&dRecNo);
    // Read next row from layer csv file
    oLayStr.clear();
    iStat1 = oCsvFilLayer.Rd_StrDS1 ( 2, &oLayStr);
  }

  oCsvFilLayer.fcloseFil(0);

  return iStat;
}
//=============================================================================
int sstDxf03FncMTextCls::WriteCsvFile(int iKey, std::string oDxfFilNam)
{
  sstMisc01AscFilCls oCsvFil;
  std::string oCsvFilNam;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  // ===== Write all Arcs to Csv file
  oCsvFilNam = oDxfFilNam + "_MText.csv";
  int iStat = oCsvFil.fopenWr(0,(char*) oCsvFilNam.c_str());
  assert(iStat >= 0);

  std::string oCsvStr;

  this->Csv_WriteHeader(0,&oCsvStr);
  oCsvFil.Wr_StrDS1(0, &oCsvStr);

  for(dREC04RECNUMTYP kk = 1; kk <= this->count(); kk++)
  {

    sstDxf03TypMTextCls oDxfMText;
    iStat = this->Read(0,kk,&oDxfMText);

    // oDxfArc.setArcID(kk);
    oDxfMText.setRecordID(kk);

    this->Csv_Write( 0, &oDxfMText, &oCsvStr);
    oCsvFil.Wr_StrDS1(0, &oCsvStr);
  }

  iStat = oCsvFil.fcloseFil(0);
  return iStat;
}
//=============================================================================
