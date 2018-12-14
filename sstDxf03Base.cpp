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
//  sstDxf03Base.cpp   14.12.18  Re.   27.02.16  Re.
//
//  Functions for sst dxf Base Classes
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
sstDxf03TypBaseCls::sstDxf03TypBaseCls()
{
  this->dRecordID = 0;
  this->dLayerID = 0;
  this->dBlockID = 0;
  this->dLinetypeID = 0;
  this->dMainRecNo = 0;
  this->color = 0;
  this->color24 = 0;
  this->width = 0;
  this->handle = 0;
}
//=============================================================================
int sstDxf03TypBaseCls::getColor() const
{
  return color;
}
//=============================================================================
void sstDxf03TypBaseCls::setColor(int value)
{
  color = value;
}
//=============================================================================
void sstDxf03TypBaseCls::BaseReadFromDL(const DL_Attributes oDLAttrib)
{
  // this->dLinetypeID = oDLAttrib.getLineType();
  this->color = oDLAttrib.getColor();
  this->color24 = oDLAttrib.getColor24();
  this->width = oDLAttrib.getWidth();
  this->handle = oDLAttrib.getHandle();
}
//=============================================================================
void sstDxf03TypBaseCls::BaseWritToDL(DL_Attributes *poDLAttrib)
{
  poDLAttrib->setColor( this->color);
  poDLAttrib->setColor24(this->color24);
  poDLAttrib->setWidth(this->width);
  poDLAttrib->setHandle(this->handle);

}
//=============================================================================
dREC04RECNUMTYP sstDxf03TypBaseCls::getBlockID() const
{
return dBlockID;
}
//=============================================================================
void sstDxf03TypBaseCls::setBlockID(const dREC04RECNUMTYP &value)
{
dBlockID = value;
}
//=============================================================================
dREC04RECNUMTYP sstDxf03TypBaseCls::getLayerID() const
{
return dLayerID;
}
//=============================================================================
void sstDxf03TypBaseCls::setLayerID(const dREC04RECNUMTYP &value)
{
dLayerID = value;
}
//=============================================================================
dREC04RECNUMTYP sstDxf03TypBaseCls::getRecordID() const
{
return dRecordID;
}
//=============================================================================
void sstDxf03TypBaseCls::setRecordID(const dREC04RECNUMTYP &value)
{
dRecordID = value;
}
//=============================================================================
dREC04RECNUMTYP sstDxf03TypBaseCls::getLinetypeID() const
{
return dLinetypeID;
}
//=============================================================================
void sstDxf03TypBaseCls::setLinetypeID(const dREC04RECNUMTYP &value)
{
dLinetypeID = value;
}
//=============================================================================
int sstDxf03TypBaseCls::getColor24() const
{
return color24;
}
//=============================================================================
void sstDxf03TypBaseCls::setColor24(int value)
{
color24 = value;
}
//=============================================================================
int sstDxf03TypBaseCls::getWidth() const
{
return width;
}
//=============================================================================
void sstDxf03TypBaseCls::setWidth(int value)
{
width = value;
}
//=============================================================================
int sstDxf03TypBaseCls::getHandle() const
{
return handle;
}
//=============================================================================
void sstDxf03TypBaseCls::setHandle(int value)
{
handle = value;
}
//=============================================================================
// Constructor
sstDxf03FncBaseCls::sstDxf03FncBaseCls(dREC04RECSIZTYP iSize):sstRec04Cls(iSize)
{
  this->oCsvRow.SetBracket(0,(char*)"\x22");  // quotation marks
  // Set Bool type 0 / 1
  this->oCsvRow.SetBoolTyp( 0, 0);
  this->oCsvRow.setUiDec(4);  // Set double/float csv writing to 4 decimal places
}
//=============================================================================
// Csv Read Function
int sstDxf03FncBaseCls::Csv_BaseRead1(int                 iKey,
                                     std::string        *oErrStr,
                                     std::string        *ssstDxfLib_Str,
                                     sstDxf03TypBaseCls *oAttributes)
{
  dREC04RECNUMTYP dLocRecordNo = 0; // Record number in sst table
  oCsvRow.SetReadPositon(0,0);

  int iStat = 0;
  int iRet  = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  if (iStat >= 0) iStat = oCsvRow.CsvString2_UInt4( 0, ssstDxfLib_Str, &dLocRecordNo);
  if (iStat >= 0) oAttributes->setRecordID(dLocRecordNo);

  if (iStat >= 0) iStat = oCsvRow.CsvString2_UInt4( 0, ssstDxfLib_Str, &dLocRecordNo);
  if (iStat >= 0) oAttributes->setLayerID(dLocRecordNo);

  if (iStat >= 0) iStat = oCsvRow.CsvString2_UInt4( 0, ssstDxfLib_Str, &dLocRecordNo);
  if (iStat >= 0) oAttributes->setBlockID(dLocRecordNo);

  *oErrStr = oCsvRow.GetErrorString();

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
int sstDxf03FncBaseCls::Csv_BaseWrite1(int iKey, sstDxf03TypBaseCls oAttributes, std::string *ssstDxfLib_Str)
{
  int iStat = 0;

  if ( iKey != 0) return -1;

  if (iStat >= 0) iStat = oCsvRow.Csv_UInt4_2String( 0, oAttributes.getRecordID(), ssstDxfLib_Str);
  if (iStat >= 0) iStat = oCsvRow.Csv_UInt4_2String( 0, oAttributes.getLayerID(), ssstDxfLib_Str);
  if (iStat >= 0) iStat = oCsvRow.Csv_UInt4_2String( 0, oAttributes.getBlockID(), ssstDxfLib_Str);

  return iStat;
}
//=============================================================================
int sstDxf03FncBaseCls::Csv_BaseHeader1(int iKey, std::string *ssstDxfLib_Str)
{
  std::string oTitelStr;
  int iStat = 0;

  // "RecordNo";"LayerNo";"BlockNo"

  if ( iKey != 0) return -1;

  oTitelStr = "RecordNo";  // Record number in type table
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "LayerNo";  // record number in layer table
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "BlockNo";  // record number in block table
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);

  assert(iStat >= 0);

  return iStat;
}
//=============================================================================
// Csv Read Function
int sstDxf03FncBaseCls::Csv_BaseRead2(int                 iKey,
                                     std::string        *oErrStr,
                                     std::string        *ssstDxfLib_Str,
                                     sstDxf03TypBaseCls *oAttributes)
{
    dREC04RECNUMTYP dLocLinetypeID; /**< Identifier in Linetype table */
    int iLocColor;                   /**< color */
    int iLocColor24;                 /**< color24 */
    int iLocWidth;                   /**< width */
    int iLocHandle;                  /**< handle */

  int iStat = 0;
  int iRet  = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  if (iStat >= 0) iStat = oCsvRow.CsvString2_UInt4( 0, ssstDxfLib_Str, &dLocLinetypeID);
  if (iStat >= 0) oAttributes->setLinetypeID(dLocLinetypeID);

  if (iStat >= 0) iStat = oCsvRow.CsvString2_Int2( 0, ssstDxfLib_Str, &iLocColor);
  if (iStat >= 0) oAttributes->setColor(iLocColor);

  if (iStat >= 0) iStat = oCsvRow.CsvString2_Int2( 0, ssstDxfLib_Str, &iLocColor24);
  if (iStat >= 0) oAttributes->setColor24(iLocColor24);

  if (iStat >= 0) iStat = oCsvRow.CsvString2_Int2( 0, ssstDxfLib_Str, &iLocWidth);
  if (iStat >= 0) oAttributes->setWidth(iLocWidth);

  if (iStat >= 0) iStat = oCsvRow.CsvString2_Int2( 0, ssstDxfLib_Str, &iLocHandle);
  if (iStat >= 0) oAttributes->setHandle(iLocHandle);

  *oErrStr = oCsvRow.GetErrorString();

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
int sstDxf03FncBaseCls::Csv_BaseWrite2(int iKey, sstDxf03TypBaseCls oAttributes, std::string *ssstDxfLib_Str)
{
  int iStat = 0;

  if ( iKey != 0) return -1;

  if (iStat >= 0) iStat = oCsvRow.Csv_UInt4_2String( 0, oAttributes.getLinetypeID(), ssstDxfLib_Str);
  if (iStat >= 0) iStat = oCsvRow.Csv_UInt2_2String( 0, oAttributes.getColor(), ssstDxfLib_Str);
  if (iStat >= 0) iStat = oCsvRow.Csv_UInt2_2String( 0, oAttributes.getColor24(), ssstDxfLib_Str);
  if (iStat >= 0) iStat = oCsvRow.Csv_UInt2_2String( 0, oAttributes.getWidth(), ssstDxfLib_Str);
  if (iStat >= 0) iStat = oCsvRow.Csv_Int2_2String( 0, oAttributes.getHandle(), ssstDxfLib_Str);

  return iStat;
}
//=============================================================================
int sstDxf03FncBaseCls::Csv_BaseHeader2(int iKey, std::string *ssstDxfLib_Str)
{
  std::string oTitelStr;
  int iStat = 0;

  if ( iKey != 0) return -1;

  oTitelStr = "LineTypeID";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "Color";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "Color24";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "Width";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "Handle";
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
dREC04RECNUMTYP sstDxf03TypBaseCls::getMainRecNo() const
{
return dMainRecNo;
}
//=============================================================================
void sstDxf03TypBaseCls::setMainRecNo(const dREC04RECNUMTYP &value)
{
dMainRecNo = value;
}
//=============================================================================
