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
// sstDxf03Lib.cpp    23.02.18  Re.    18.11.16  Re.
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
sstDxf03DbCls::sstDxf03DbCls(sstMisc01PrtFilCls *oTmpPrt)
{
  // Constructor
  this->poDxf03DbIntern = new sstDxf03DatabaseCls(oTmpPrt);
}
//=============================================================================
sstDxf03DbCls::~sstDxf03DbCls()
{
  // Destructor
  delete(this->poDxf03DbIntern);
}
//=============================================================================
int sstDxf03DbCls::WriteNewArc (int                   iKey,
                                const DL_ArcData      oDLArc,
                                const DL_Attributes   attributes,
                                dREC04RECNUMTYP      *oEntRecNo,
                                dREC04RECNUMTYP      *oMainRecNo)
{
  return this->poDxf03DbIntern->WriteNewArc ( iKey, oDLArc, attributes, oEntRecNo, oMainRecNo);
}
//=============================================================================
int sstDxf03DbCls::WriteNewCircle(int iKey,
                   const DL_CircleData oDLCircle,
                   const DL_Attributes attributes,
                   dREC04RECNUMTYP *oEntRecNo,
                   dREC04RECNUMTYP *oMainRecNo)
{
  return this->poDxf03DbIntern->WriteNewCircle(iKey,oDLCircle,attributes,oEntRecNo, oMainRecNo);
}
//==============================================================================
int sstDxf03DbCls::WriteArc (int                    iKey,
                             const DL_ArcData       oDlArc,
                             const DL_Attributes    oDLAttributes,
                             dREC04RECNUMTYP       *oEntRecNo,
                             dREC04RECNUMTYP       *oMainRecNo)
{
  return this->poDxf03DbIntern->WriteArc(iKey,oDlArc,oDLAttributes,oEntRecNo, oMainRecNo);
}
//==============================================================================
int sstDxf03DbCls::WriteCircle (int iKey,
               const DL_CircleData    oDlCircle,
               const DL_Attributes  oDLAttributes,
               dREC04RECNUMTYP     *oEntRecNo,
               dREC04RECNUMTYP     *oMainRecNo)
{
  return this->poDxf03DbIntern->WriteCircle(iKey,oDlCircle,oDLAttributes,oEntRecNo, oMainRecNo);
}
//=============================================================================
int sstDxf03DbCls::WriteLine(int iKey,
                   const DL_LineData oDLLine,
                   const DL_Attributes attributes,
                   dREC04RECNUMTYP *oEntRecNo,
                   dREC04RECNUMTYP *oMainRecNo)
{
  return this->poDxf03DbIntern->WriteLine(iKey,oDLLine,attributes,oEntRecNo, oMainRecNo);
}
//==============================================================================
int sstDxf03DbCls::OpenNewHatch(int                  iKey,
                                const DL_HatchData   oDLHatch,
                                const DL_Attributes  oDLAttributes,
                                dREC04RECNUMTYP     *oEntRecNo,
                                dREC04RECNUMTYP     *oMainRecNo)
//-----------------------------------------------------------------------------
{
  if ( iKey != 0) return -1;

  return this->poDxf03DbIntern->OpenNewHatch(iKey,oDLHatch,oDLAttributes,oEntRecNo, oMainRecNo);
}
//==============================================================================
int sstDxf03DbCls::OpenNewPolyline(int                  iKey,
                                const DL_PolylineData   oDlPolyline,
                                const DL_Attributes  oDLAttributes,
                                dREC04RECNUMTYP     *oEntRecNo,
                                dREC04RECNUMTYP     *oMainRecNo)
//-----------------------------------------------------------------------------
{
  if ( iKey != 0) return -1;

  return this->poDxf03DbIntern->OpenNewPolyline(iKey,oDlPolyline,oDLAttributes,oEntRecNo, oMainRecNo);
}
//==============================================================================
int sstDxf03DbCls::WriteNewHatchEdge (int                    iKey,
                                      const DL_HatchEdgeData oDLHatchEdge,
                                      dREC04RECNUMTYP       *oEntRecNo,
                                      dREC04RECNUMTYP       *oMainRecNo)
//-----------------------------------------------------------------------------
{
  if ( iKey != 0) return -1;

  return this->poDxf03DbIntern->WriteNewHatchEdge(iKey,oDLHatchEdge,oEntRecNo, oMainRecNo);
}
//==============================================================================
int sstDxf03DbCls::WriteNewVertex (int                   iKey,
                                   const DL_VertexData   oDlVertex,
                                   dREC04RECNUMTYP      *oEntRecNo,
                                   dREC04RECNUMTYP      *oMainRecNo)
//-----------------------------------------------------------------------------
{
  if ( iKey != 0) return -1;

  return this->poDxf03DbIntern->WriteNewVertex( iKey, oDlVertex, oEntRecNo, oMainRecNo);
}
//==============================================================================
int sstDxf03DbCls::WriteVertex (int                   iKey,
                                const DL_VertexData   oDlVertex,
                                dREC04RECNUMTYP      *oEntRecNo,
                                dREC04RECNUMTYP      *oMainRecNo)
//-----------------------------------------------------------------------------
{
  if ( iKey != 0) return -1;

  return this->poDxf03DbIntern->WriteVertex( iKey, oDlVertex, oEntRecNo, oMainRecNo);
}
//=============================================================================
int sstDxf03DbCls::WritAll2DxfFil(int iKey, const std::string oDxfFilNam)
{
  return this->poDxf03DbIntern->WritAll2DxfFil(iKey, oDxfFilNam);
}
//=============================================================================
int sstDxf03DbCls::WritAll2Csv(int iKey, const std::string oDxfFilNam)
{
  return this->poDxf03DbIntern->WritAll2Csv(iKey,oDxfFilNam);
}
//=============================================================================
int sstDxf03DbCls::ReadAllCsvFiles(int iKey, std::string oDxfFilNam)
{
  return this->poDxf03DbIntern->ReadAllCsvFiles(iKey, oDxfFilNam);
}
//=============================================================================
int sstDxf03DbCls::ReadAllFromDxf(int iKey, const std::string oDxfFilNam)
{
  return this->poDxf03DbIntern->ReadAllFromDxf(iKey, oDxfFilNam);
}
//=============================================================================
dREC04RECNUMTYP sstDxf03DbCls::MainCount()
{
  return this->poDxf03DbIntern->MainCount();
}
//=============================================================================
dREC04RECNUMTYP sstDxf03DbCls::EntityCount(RS2::EntityType eEntityType)
{
  return this->poDxf03DbIntern->EntityCount(eEntityType);
}
//=============================================================================
int sstDxf03DbCls::ColumnCount(RS2::EntityType eEntityType)
{
  return this->poDxf03DbIntern->ColumnCount(eEntityType);
}
//=============================================================================
int sstDxf03DbCls::ReadHatch ( int iKey, dREC04RECNUMTYP dRecNo, DL_HatchData *oDLHatch, DL_Attributes *oDLAttributes)
{
  return this->poDxf03DbIntern->ReadHatch(iKey,dRecNo, oDLHatch, oDLAttributes);
}
//=============================================================================
int sstDxf03DbCls::ReadHatchEdge( int iKey, dREC04RECNUMTYP dRecNo, DL_HatchEdgeData *oDLHatchEdge)
{
  return this->poDxf03DbIntern->ReadHatchEdge(iKey, dRecNo, oDLHatchEdge);
}
//=============================================================================
int sstDxf03DbCls::ReadHatchLoop( int iKey, dREC04RECNUMTYP dRecNo, DL_HatchLoopData *oDLHatchLoop)
{
  return this->poDxf03DbIntern->ReadHatchLoop(iKey, dRecNo, oDLHatchLoop);
}
//=============================================================================
int sstDxf03DbCls::ReadCircle ( int iKey, dREC04RECNUMTYP dRecNo, DL_CircleData *oDLCircle, DL_Attributes *oDLAttributes)
{
  return this->poDxf03DbIntern->ReadCircle(iKey,dRecNo, oDLCircle, oDLAttributes);
}
//=============================================================================
int sstDxf03DbCls::ReadVertex( int iKey, dREC04RECNUMTYP dRecNo, DL_VertexData *oDLVertex)
{
  return this->poDxf03DbIntern->ReadVertex(iKey,dRecNo, oDLVertex);
}
//=============================================================================
int sstDxf03DbCls::ReadLine ( int iKey, dREC04RECNUMTYP dRecNo, DL_LineData *oDLLine, DL_Attributes *oDLAttributes)
{
  return this->poDxf03DbIntern->ReadLine(iKey,dRecNo, oDLLine, oDLAttributes);
}
//=============================================================================
int sstDxf03DbCls::ReadPolyline ( int iKey, dREC04RECNUMTYP dRecNo, DL_PolylineData *oDLPolyline, DL_Attributes *oDLAttributes)
{
  return this->poDxf03DbIntern->ReadPolyline(iKey,dRecNo, oDLPolyline, oDLAttributes);
}
//=============================================================================
int sstDxf03DbCls::ReadBlock ( int iKey, dREC04RECNUMTYP dRecNo, DL_BlockData *oDLBlock, DL_Attributes *oDLAttributes)
{
  return this->poDxf03DbIntern->ReadBlock(iKey,dRecNo, oDLBlock, oDLAttributes);
}
//=============================================================================
int sstDxf03DbCls::ReadMainTable( int iKey, dREC04RECNUMTYP dMainRecNo, RS2::EntityType *eEntityType, dREC04RECNUMTYP *dEntRecNo)
{
  return this->poDxf03DbIntern->ReadMainTable(iKey,dMainRecNo, eEntityType, dEntRecNo);
}
//=============================================================================
sstMath01Mbr2Cls sstDxf03DbCls::getMbrModel()
{
  return this->poDxf03DbIntern->getMbrModel();
}
//=============================================================================
sstMath01Mbr2Cls sstDxf03DbCls::getMbrBlock(dREC04RECNUMTYP dBlkNo)
{
  return this->poDxf03DbIntern->getMbrBlock( dBlkNo);
}
//=============================================================================
dREC04RECNUMTYP sstDxf03DbCls::countBlocks()
{
  return this->poDxf03DbIntern->countBlocks();
}
//=============================================================================
dREC04RECNUMTYP sstDxf03DbCls::countEntities(int iKey, dREC04RECNUMTYP dBlkNo)
{
  return this->poDxf03DbIntern->countEntities(iKey, dBlkNo);
}
//=============================================================================
int sstDxf03DbCls::ReadEntityType(int iKey,
                                  dREC04RECNUMTYP dBlkNo,
                                  dREC04RECNUMTYP dMainNo,
                                  RS2::EntityType *eEntType,
                                  dREC04RECNUMTYP *dEntNo)
{
  return this->poDxf03DbIntern->ReadEntityType(iKey, dBlkNo, dMainNo, eEntType,dEntNo);
}
//==============================================================================
int sstDxf03DbCls::WritePoint (int iKey,
               const DL_PointData    oDlPoint,
               const DL_Attributes  oDLAttributes,
               dREC04RECNUMTYP     *oEntRecNo,
               dREC04RECNUMTYP     *oMainRecNo)
{
  return this->poDxf03DbIntern->WritePoint(iKey,oDlPoint,oDLAttributes,oEntRecNo, oMainRecNo);
}
//==============================================================================
int sstDxf03DbCls::ReadPoint ( int              iKey,
                               dREC04RECNUMTYP  dRecNo,
                               DL_PointData    *oDlPoint,
                               DL_Attributes   *oDLAttributes)
{
  return this->poDxf03DbIntern->ReadPoint(iKey,dRecNo, oDlPoint, oDLAttributes);
}
//==============================================================================
int sstDxf03DbCls::WriteMText (int                  iKey,
                               const DL_MTextData   oDlMText,
                               const DL_Attributes  oDLAttributes,
                               dREC04RECNUMTYP     *oEntRecNo,
                               dREC04RECNUMTYP     *oMainRecNo)
{
  return this->poDxf03DbIntern->WriteMText(iKey,oDlMText,oDLAttributes,oEntRecNo, oMainRecNo);
}
//==============================================================================
int sstDxf03DbCls::ReadMText ( int iKey,
               dREC04RECNUMTYP dRecNo,
               DL_MTextData *oDlMText,
               DL_Attributes *oDLAttributes)
{
  return this->poDxf03DbIntern->ReadMText(iKey,dRecNo, oDlMText, oDLAttributes);
}
//==============================================================================
int sstDxf03DbCls::WriteText (int iKey,
               const DL_TextData    oDlText,
               const DL_Attributes  oDLAttributes,
               dREC04RECNUMTYP     *oEntRecNo,
               dREC04RECNUMTYP     *oMainRecNo)
{
  return this->poDxf03DbIntern->WriteText(iKey,oDlText,oDLAttributes,oEntRecNo, oMainRecNo);
}
//==============================================================================
int sstDxf03DbCls::ReadText ( int iKey,
               dREC04RECNUMTYP dRecNo,
               DL_TextData *oDlText,
               DL_Attributes *oDLAttributes)
{
  return this->poDxf03DbIntern->ReadText(iKey,dRecNo, oDlText, oDLAttributes);
}
//==============================================================================
int sstDxf03DbCls::WriteInsert (int iKey,
               const DL_InsertData    oDlInsert,
               const DL_Attributes  oDLAttributes,
               dREC04RECNUMTYP     *oEntRecNo,
               dREC04RECNUMTYP     *oMainRecNo)
{
  return this->poDxf03DbIntern->WriteInsert(iKey,oDlInsert,oDLAttributes,oEntRecNo, oMainRecNo);
}
//==============================================================================
int sstDxf03DbCls::ReadInsert ( int iKey,
               dREC04RECNUMTYP dRecNo,
               DL_InsertData *oDlInsert,
               DL_Attributes *oDLAttributes)
{
  return this->poDxf03DbIntern->ReadInsert(iKey,dRecNo, oDlInsert, oDLAttributes);
}
//==============================================================================
int sstDxf03DbCls::GenerateData ( int iKey)
{
  return this->poDxf03DbIntern->GenerateData(iKey);
}
//==============================================================================
std::string sstDxf03DbCls::CnvtTypeEnum2String(RS2::EntityType eEntityType)
{
  std::string oTmpStr;
  sstDxf03EntityTypeCls oEntTypeCnvt;
  oTmpStr = oEntTypeCnvt.Enum2String(eEntityType);
  return oTmpStr;
}
//==============================================================================
RS2::EntityType sstDxf03DbCls::CnvtTypeString2Enum(std::string oEntityStr)
{
  RS2::EntityType eTmpType;
  sstDxf03EntityTypeCls oEntTypeCnvt;
  eTmpType = oEntTypeCnvt.String2Enum(oEntityStr);
  return eTmpType;
}
//==============================================================================
// Get Main Table record number
dREC04RECNUMTYP sstDxf03DbCls::getMainTabRecNo(int iKey, RS2::EntityType eEntityType, dREC04RECNUMTYP dEntRecNo)
{
  return this->poDxf03DbIntern->getMainTabRecNo ( iKey, eEntityType, dEntRecNo);
}
//==============================================================================
// Get Section Entities record number, is main table record number minus all block records
dREC04RECNUMTYP sstDxf03DbCls::getSectEntRecNo(int iKey, RS2::EntityType eEntityType, dREC04RECNUMTYP dEntRecNo)
{
  return this->poDxf03DbIntern->getSectEntRecNo( iKey, eEntityType, dEntRecNo);
}
//==============================================================================
int sstDxf03DbCls::openBlock(int iKey,  const DL_BlockData& data, const DL_Attributes attributes)
{
  return this->poDxf03DbIntern->openBlock(iKey, data, attributes);
}
//==============================================================================
int sstDxf03DbCls::closeBlock(int iKey)
{
  return this->poDxf03DbIntern->closeBlock(iKey);
}
//==============================================================================
int sstDxf03DbCls::openSectionEntities(int iKey)
{
  return this->poDxf03DbIntern->openSectionEntities(iKey);
}
//==============================================================================
dREC04RECNUMTYP sstDxf03DbCls::getBlkStartMainTab(int iKey, dREC04RECNUMTYP dEntRecNo)
{
  return this->poDxf03DbIntern->getBlkStartMainTab(iKey,dEntRecNo);
}
//==============================================================================
dREC04RECNUMTYP sstDxf03DbCls::searchBlkNoWithName(int iKey, const std::string oBlkNamStr)
{
  return this->poDxf03DbIntern->searchBlkNoWithName( iKey, oBlkNamStr);
}
//==============================================================================
