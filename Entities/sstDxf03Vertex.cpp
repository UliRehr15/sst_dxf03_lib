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
//  sstDxf03Vertex.cpp   01.11.16  Re.   29.04.16  Re.
//
//  Functions for sst Dxf Vertex Classes
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
sstDxf03TypVertexCls::sstDxf03TypVertexCls()
{
  this->dRecordID = 0;
  this->dParentID = 0;
  this->eEntityType = RS2::EntityUnknown;

  this->bulge = 0.0;
  this->x = 0.0;
  this->y = 0.0;
  this->z = 0.0;
}
//=============================================================================
// Set Test Data
int sstDxf03TypVertexCls::SetTestData(int iKey)
{
  if ( iKey != 0) return -1;

  this->dRecordID = 5;
  this->dParentID = 2;
  this->eEntityType = RS2::EntityPolyline;

  this->bulge = -1.5;
  this->x = 111.1;
  this->y = 222.2;
  this->z = 333.3;
  return 0;
}
//=============================================================================
void sstDxf03TypVertexCls::ReadFromDL(const DL_VertexData oDLVertex)
{
  this->bulge = oDLVertex.bulge;
  // this->dRecordID = 0;
  this->x = oDLVertex.x;
  this->y = oDLVertex.y;
  this->z = oDLVertex.z;
}
//=============================================================================
void sstDxf03TypVertexCls::WritToDL(DL_VertexData *poDLVertex)
{
  poDLVertex->bulge = this->bulge;
  // this->dRecordID = 0;
  poDLVertex->x = this->x;
  poDLVertex->y = this->y;
  poDLVertex->z = this->z;
}
//=============================================================================
dREC04RECNUMTYP sstDxf03TypVertexCls::getRecordID() const
{
return dRecordID;
}
//=============================================================================
void sstDxf03TypVertexCls::setRecordID(const dREC04RECNUMTYP &value)
{
dRecordID = value;
}
//=============================================================================
dREC04RECNUMTYP sstDxf03TypVertexCls::getParentID() const
{
return dParentID;
}
//=============================================================================
void sstDxf03TypVertexCls::setParentID(const dREC04RECNUMTYP &value)
{
dParentID = value;
}
//=============================================================================
RS2::EntityType sstDxf03TypVertexCls::getEntityType() const
{
return eEntityType;
}
//=============================================================================
void sstDxf03TypVertexCls::setEntityType(const RS2::EntityType &value)
{
eEntityType = value;
}
//=============================================================================
double sstDxf03TypVertexCls::getX() const
{
return x;
}
//=============================================================================
void sstDxf03TypVertexCls::setX(double value)
{
x = value;
}
//=============================================================================
double sstDxf03TypVertexCls::getY() const
{
return y;
}
//=============================================================================
void sstDxf03TypVertexCls::setY(double value)
{
y = value;
}
//=============================================================================
double sstDxf03TypVertexCls::getZ() const
{
return z;
}
//=============================================================================
void sstDxf03TypVertexCls::setZ(double value)
{
z = value;
}
//=============================================================================
double sstDxf03TypVertexCls::getBulge() const
{
return bulge;
}
//=============================================================================
void sstDxf03TypVertexCls::setBulge(double value)
{
bulge = value;
}
//=============================================================================
// Constructor
sstDxf03FncVertexCls::sstDxf03FncVertexCls():sstDxf03FncBaseCls(sizeof(sstDxf03TypVertexCls))
{
  // this->poDxfArcMem = new sstRec04Cls(sizeof(sstDxf03TypVertexCls));
}
//=============================================================================
// Csv Read Function
int sstDxf03FncVertexCls::Csv_Read(int iKey, std::string *oErrStr, std::string *ssstDxfLib_Str, sstDxf03TypVertexCls *osstDxf03TypVertexCls)
{
//  DL_VertexData sDLArc(0.0,0.0,0.0,0.0);
//  dREC04RECNUMTYP dTmpID = 0;
//  unsigned long ulTmpLayerID = 0;
//  unsigned long ulTmpBlockID = 0;
  // sstStr01Cls oCsvRow;

  dREC04RECNUMTYP dLocRecordID; /**< ID of vertex */
  dREC04RECNUMTYP dLocParentID; /**< ID of parent object */
  RS2::EntityType eLocEntityType;     /**< Polyline and so on ... */
  double dLocX;  /*! X Coordinate of the vertex. */
  double dLocY;  /*! Y Coordinate of the vertex. */
  double dLocZ;  /*! Z Coordinate of the vertex. */
  double dLocBulge;  /*! Bulge of vertex. (The tangent of 1/4 of the arc angle or 0 for lines) */

  sstDxf03EntityTypeCls oEntType;
  std::string oLocTypeStr;

  int iStat = 0;
  int iRet  = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  oCsvRow.SetReadPositon(0,0);

//  dREC04RECNUMTYP dRecordID; /**< ID of vertex */
//  dREC04RECNUMTYP dParentID; /**< ID of parent object */
//  RS2::EntityType eEntityType;     /**< Polyline and so on ... */
//  double x;  /*! X Coordinate of the vertex. */
//  double y;  /*! Y Coordinate of the vertex. */
//  double z;  /*! Z Coordinate of the vertex. */
//  double bulge;  /*! Bulge of vertex. (The tangent of 1/4 of the arc angle or 0 for lines) */

  if (iStat >= 0) iStat = oCsvRow.CsvString2_UInt4( 0, ssstDxfLib_Str, &dLocRecordID);
  if (iStat >= 0) osstDxf03TypVertexCls->setRecordID(dLocRecordID);

  if (iStat >= 0) iStat = oCsvRow.CsvString2_UInt4( 0, ssstDxfLib_Str, &dLocParentID);
  if (iStat >= 0) osstDxf03TypVertexCls->setParentID(dLocParentID);

  if (iStat >= 0) iStat = oCsvRow.CsvString2_Str( 0, ssstDxfLib_Str, &oLocTypeStr);
  eLocEntityType = oEntType.String2Enum(oLocTypeStr);
  if (iStat >= 0) osstDxf03TypVertexCls->setEntityType(eLocEntityType);

  if (iStat >= 0) iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxfLib_Str, &dLocX);
  if (iStat >= 0) osstDxf03TypVertexCls->setX(dLocX);

  if (iStat >= 0) iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxfLib_Str, &dLocY);
  if (iStat >= 0) osstDxf03TypVertexCls->setY(dLocY);

  if (iStat >= 0) iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxfLib_Str, &dLocZ);
  if (iStat >= 0) osstDxf03TypVertexCls->setZ(dLocZ);

  if (iStat >= 0) iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxfLib_Str, &dLocBulge);
  if (iStat >= 0) osstDxf03TypVertexCls->setBulge(dLocBulge);


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
int sstDxf03FncVertexCls::Csv_Write(int iKey, sstDxf03TypVertexCls *poSstVertex, std::string *ssstDxfLib_Str)
{

  if ( iKey != 0) return -1;

  int iStat = 0;
  sstDxf03EntityTypeCls oEntityCnvt;
  std::string oLocEntityStr;

//  dREC04RECNUMTYP dRecordID; /**< ID of vertex */
//  dREC04RECNUMTYP dParentID; /**< ID of parent object */
//  RS2::EntityType eEntityType;     /**< Polyline and so on ... */
//  double x;  /*! X Coordinate of the vertex. */
//  double y;  /*! Y Coordinate of the vertex. */
//  double z;  /*! Z Coordinate of the vertex. */
//  double bulge;  /*! Bulge of vertex. (The tangent of 1/4 of the arc angle or 0 for lines) */


  ssstDxfLib_Str->clear();

  if (iStat >= 0) iStat = oCsvRow.Csv_UInt4_2String( 0, poSstVertex->getRecordID(), ssstDxfLib_Str);
  if (iStat >= 0) iStat = oCsvRow.Csv_UInt4_2String( 0, poSstVertex->getParentID(), ssstDxfLib_Str);
  oLocEntityStr = oEntityCnvt.Enum2String(poSstVertex->getEntityType());
  if (iStat >= 0) iStat = oCsvRow.Csv_Str_2String( 0, oLocEntityStr, ssstDxfLib_Str);

  if (iStat >= 0) iStat = oCsvRow.Csv_Dbl_2String( 0, poSstVertex->getX(), ssstDxfLib_Str);
  if (iStat >= 0) iStat = oCsvRow.Csv_Dbl_2String( 0, poSstVertex->getY(), ssstDxfLib_Str);
  if (iStat >= 0) iStat = oCsvRow.Csv_Dbl_2String( 0, poSstVertex->getZ(), ssstDxfLib_Str);
  if (iStat >= 0) iStat = oCsvRow.Csv_Dbl_2String( 0, poSstVertex->getBulge(), ssstDxfLib_Str);

  return iStat;
}
//=============================================================================
int sstDxf03FncVertexCls::Csv_WriteHeader(int iKey, std::string *ssstDxfLib_Str)
{
  std::string oTitelStr;
  int iStat = 0;

  if ( iKey != 0) return -1;

  ssstDxfLib_Str->clear();

//  dREC04RECNUMTYP dRecordID; /**< ID of vertex */
//  dREC04RECNUMTYP dParentID; /**< ID of parent object */
//  RS2::EntityType eEntityType;     /**< Polyline and so on ... */
//  double x;  /*! X Coordinate of the vertex. */
//  double y;  /*! Y Coordinate of the vertex. */
//  double z;  /*! Z Coordinate of the vertex. */
//  double bulge;  /*! Bulge of vertex. (The tangent of 1/4 of the arc angle or 0 for lines) */

  oTitelStr = "VertexID";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "ParentID";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "ParentType";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);

  oTitelStr = "Value X";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "Value Y";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "Value Z";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "Bulge";
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
int sstDxf03FncVertexCls::ReadCsvFile(int iKey, std::string oFilNam)
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
    sstDxf03TypVertexCls oSstArc;
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
int sstDxf03FncVertexCls::WriteCsvFile(int iKey, std::string oDxfFilNam)
{
  sstMisc01AscFilCls oCsvFil;
  std::string oCsvFilNam;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  // ===== Write all Insert to Csv file
  oCsvFilNam = oDxfFilNam + "_Vertex.csv";
  int iStat = oCsvFil.fopenWr(0,(char*) oCsvFilNam.c_str());
  assert(iStat >= 0);

  std::string oCsvStr;

  this->Csv_WriteHeader(0,&oCsvStr);
  oCsvFil.Wr_StrDS1(0, &oCsvStr);

  for(dREC04RECNUMTYP kk = 1; kk <= this->count(); kk++)
  {

    sstDxf03TypVertexCls oDxfVertex;
    iStat = this->Read(0,kk,&oDxfVertex);

    oDxfVertex.setRecordID(kk);

    this->Csv_Write( 0, &oDxfVertex, &oCsvStr);
    oCsvFil.Wr_StrDS1(0, &oCsvStr);
  }

  iStat = oCsvFil.fcloseFil(0);
  return iStat;
}
//=============================================================================
