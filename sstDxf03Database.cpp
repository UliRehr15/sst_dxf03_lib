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
//  sstDxf03Database.cpp   25.05.18  Re.   06.07.16  Re.
//
//  Functions for Class "sstDxf03DatabaseCls"
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

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

#include "sstDxf03LibInt.h"

//=============================================================================
sstDxf03DatabaseCls::sstDxf03DatabaseCls(sstMisc01PrtFilCls *oTmpPrt)
{
  // And open all sst dxf tables

  this->oPrt = oTmpPrt;
  dMainTabSectEntStart = 0;                    // Start of section entities in main table
  eActEntType = RS2::EntityUnknown;            // Actual Entity Type

  eGrpEntType = RS2::EntityUnknown;            // Group Entity Type
  dGrpMainID = 0;             // Group Main ID
  dGrpSubID = 0;              // Sub Group ID like HatchLoop
  dGrpRecNum = 0;             // Number of entities

  //=== default Write LineType in database =====================================

  sstDxf03FncLTypeCls *oLTypeTab;
  sstDxf03TypLTypeCls oLTypeRec;
  dREC04RECNUMTYP dRecNo = 0;

  oLTypeRec.setLineTypeID(1);
  oLTypeRec.setName("CONTINUOUS");

  oLTypeTab = this->getSstFncLType();

  int iStat = oLTypeTab->WritNew(0,&oLTypeRec,&dRecNo);
  assert(iStat == 0);

  //=== default Write Layer 0 in database =====================================

  sstDxf03FncLayCls *oLayTab;
  sstDxf03TypLayCls oLayRec;
  // dREC04RECNUMTYP dRecNo = 0;

  DL_LayerData  oDL_Lay("0",0);
  DL_Attributes oDL_Attr;

  oDL_Attr.setLinetype("CONTINUOUS");

  oLayRec.ReadFromDL(oDL_Lay);
  oLayRec.BaseReadFromDL(oDL_Attr);

  oLayRec.setLinetypeID(1);

  oLayTab = this->getSstFncLay();

  iStat = oLayTab->WritNew(0,&oLayRec,&dRecNo);
  assert(iStat == 0);

  // default write Blocks in database modelspace / paperspace
  // Are written with close of object

}
//=============================================================================
int sstDxf03DatabaseCls::ReadAllCsvFiles(int iKey, std::string oDxfFilNam)
{
  int iStat = 0;
  sstMisc01FilNamCls oFilNamConv;
  std::string oJobNam;

  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  // remove given ending from filename
  iStat = oFilNamConv.RemoveExtension(0, "dxf", oDxfFilNam, &oJobNam);

  std::string oFilNamLayer;
  std::string oFilNamBlock;
  std::string oFilNamLType;
  std::string oFilNamArc;
  std::string oFilNamInsert;
  std::string oFilNamPolyline;
  std::string oFilNamVertex;
  std::string oFilNamHatch;
  std::string oFilNamHatchEdge;
  std::string oFilNamHatchLoop;
  std::string oFilNamCircle;
  std::string oFilNamMText;
  std::string oFilNamText;
  std::string oFilNamPoint;
  std::string oFilNamLine;
  std::string oFilNamMain;

  oFilNamLayer = oJobNam + "_Layer.csv";
  oFilNamBlock = oJobNam + "_Block.csv";
  oFilNamLType = oJobNam + "_Linetype.csv";
  oFilNamArc = oJobNam + "_Arc.csv";
  oFilNamInsert = oJobNam + "_Insert.csv";
  oFilNamPolyline = oJobNam + "_Polyline.csv";
  oFilNamVertex = oJobNam + "_Vertex.csv";
  oFilNamHatch = oJobNam + "_Hatch.csv";
  oFilNamHatchEdge = oJobNam + "_HatchEdge.csv";
  oFilNamHatchLoop = oJobNam + "_HatchLoop.csv";
  oFilNamCircle = oJobNam + "_Circle.csv";
  oFilNamMText = oJobNam + "_MText.csv";
  oFilNamText = oJobNam + "_Text.csv";
  oFilNamPoint = oJobNam + "_Point.csv";
  oFilNamLine = oJobNam + "_Line.csv";
  oFilNamMain = oJobNam + "_Main.csv";


  // Read whole main csv file into sst_rec_mem
  iStat = this->oSstFncMain.ReadCsvFile ( 0, oFilNamMain);
  // Check given arguments:
  if (iStat != 0)
  {
    // Write Message to Protocolfile and console
    iStat = this->oPrt->SST_PrtWrtChar ( 1, (char*) oFilNamMain.c_str(), (char*) "File not found: ");
    return -2;
  }

  // Read whole layer csv file into sst_rec_mem
  iStat = this->oSstFncLay.ReadCsvFile ( 0, oFilNamLayer);
  // Check given arguments:
  if (iStat != 0)
  {
    // Write Message to Protocolfile and console
    iStat = this->oPrt->SST_PrtWrtChar ( 1, (char*) oFilNamLayer.c_str(), (char*) "File not found: ");

    return -2;
  }

  // Read whole block csv file into sst_rec_mem
  iStat = oSstFncBlk.ReadCsvFile ( 0, oFilNamBlock);
  if (iStat != 0)
  {
    // Write Message to Protocolfile and console
    iStat = this->oPrt->SST_PrtWrtChar ( 1, (char*) oFilNamBlock.c_str(), (char*) "File not found: ");
  }

  // Read whole linetype csv file into sst_rec_mem
  iStat = oSstFncLType.ReadCsvFile ( 0, oFilNamLType);
  if (iStat != 0)
  {
    // Write Message to Protocolfile and console
    iStat = this->oPrt->SST_PrtWrtChar ( 1, (char*) oFilNamLType.c_str(), (char*) "File not found: ");
  }

  // Read whole insert csv file into sst_rec_mem
  iStat = oSstFncInsert.ReadCsvFile ( 0, oFilNamInsert);

  // Read whole arc csv file into sst_rec_mem
  iStat = oSstFncArc.ReadCsvFile ( 0, oFilNamArc);

  // Read whole polyline csv file into sst_rec_mem
  iStat = oSstFncPolyline.ReadCsvFile ( 0, oFilNamPolyline);

  // Read whole vertex csv file into sst_rec_mem
  iStat = oSstFncVertex.ReadCsvFile ( 0, oFilNamVertex);

  // Read whole hatch csv file into sst_rec_mem
  iStat = oSstFncHatch.ReadCsvFile ( 0, oFilNamHatch);

  // Read whole hatch edge csv file into sst_rec_mem
  iStat = oSstFncHatchEdge.ReadCsvFile ( 0, oFilNamHatchEdge);

  // Read whole hatch loop csv file into sst_rec_mem
  iStat = oSstFncHatchLoop.ReadCsvFile ( 0, oFilNamHatchLoop);

  // Read whole circle csv file into sst_rec_mem
  iStat = oSstFncCircle.ReadCsvFile ( 0, oFilNamCircle);

  // Read whole mtext csv file into sst_rec_mem
  iStat = oSstFncMText.ReadCsvFile ( 0, oFilNamMText);

  // Read whole text csv file into sst_rec_mem
  iStat = oSstFncText.ReadCsvFile ( 0, oFilNamText);

  // Read whole point csv file into sst_rec_mem
  iStat = oSstFncPoint.ReadCsvFile ( 0, oFilNamPoint);

  // Read whole line csv file into sst_rec_mem
  iStat = oSstFncLine.ReadCsvFile ( 0, oFilNamLine);

  // update all minimum bounding rectangles in main table
  iStat = this->updateAllMbr(0);

  return 0;
}
//=============================================================================
sstDxf03FncLayCls* sstDxf03DatabaseCls::getSstFncLay()
{
  return &this->oSstFncLay;
}
//=============================================================================
sstDxf03FncBlkCls* sstDxf03DatabaseCls::getSstFncBlk()
{
  return &this->oSstFncBlk;
}
//=============================================================================
sstDxf03FncLTypeCls* sstDxf03DatabaseCls::getSstFncLType()
{
  return &this->oSstFncLType;
}
//=============================================================================
sstDxf03FncArcCls* sstDxf03DatabaseCls::getSstFncArc()
{
  return &this->oSstFncArc;
}
//=============================================================================
sstDxf03FncCircleCls* sstDxf03DatabaseCls::getSstFncCircle()
{
  return &this->oSstFncCircle;
}
//=============================================================================
sstDxf03FncMTextCls* sstDxf03DatabaseCls::getSstFncMText()
{
  return &this->oSstFncMText;
}
//=============================================================================
sstDxf03FncTextCls* sstDxf03DatabaseCls::getSstFncText()
{
  return &this->oSstFncText;
}
//=============================================================================
sstDxf03FncPointCls* sstDxf03DatabaseCls::getSstFncPoint()
{
  return &this->oSstFncPoint;
}
//=============================================================================
sstDxf03FncLineCls* sstDxf03DatabaseCls::getSstFncLine()
{
  return &this->oSstFncLine;
}
//=============================================================================
sstDxf03FncInsertCls* sstDxf03DatabaseCls::getSstFncInsert()
{
  return &this->oSstFncInsert;
}
//=============================================================================
sstDxf03FncPolylineCls* sstDxf03DatabaseCls::getSstFncPolyline()
{
  return &this->oSstFncPolyline;
}
//=============================================================================
sstDxf03FncTraceCls* sstDxf03DatabaseCls::getSstFncTrace()
{
  return &this->oSstFncTrace;
}
//=============================================================================
sstDxf03FncVertexCls* sstDxf03DatabaseCls::getSstFncVertex()
{
  return &this->oSstFncVertex;
}
//=============================================================================
sstDxf03FncHatchCls* sstDxf03DatabaseCls::getSstFncHatch()
{
  return &this->oSstFncHatch;
}
//=============================================================================
sstDxf03FncHatchLoopCls* sstDxf03DatabaseCls::getSstFncHatchLoop()
{
  return &this->oSstFncHatchLoop;
}
//=============================================================================
sstDxf03FncHatchEdgeCls* sstDxf03DatabaseCls::getSstFncHatchEdge()
{
  return &this->oSstFncHatchEdge;
}
//=============================================================================
sstDxf03FncMainCls* sstDxf03DatabaseCls::getSstFncMain()
{
  return &this->oSstFncMain;
}
//=============================================================================
dREC04RECNUMTYP sstDxf03DatabaseCls::getMainTabSectEntStart() const
{
return dMainTabSectEntStart;
}
//=============================================================================
void sstDxf03DatabaseCls::setMainTabSectEntStart(const dREC04RECNUMTYP &value)
{
  this->dMainTabSectEntStart = value;
}
//=============================================================================
RS2::EntityType sstDxf03DatabaseCls::getActEntType() const
{
return eActEntType;
}
//=============================================================================
void sstDxf03DatabaseCls::setActEntType(const RS2::EntityType &value)
{
eActEntType = value;
}
//=============================================================================
int sstDxf03DatabaseCls::WriteNewCircle(int                  iKey,
                                        const DL_CircleData  data,
                                        const DL_Attributes  attributes,
                                        dREC04RECNUMTYP     *dEntRecNo,
                                        dREC04RECNUMTYP     *dMainRecNo)
{
  if ( iKey != 0) return -1;

  int iStat = 0;
  std::string oLayerStr;

  sstDxf03TypCircleCls oDxfCircle;
  oDxfCircle.ReadFromDL(data);
  oDxfCircle.BaseReadFromDL(attributes);
  dREC04RECNUMTYP dLayRecNo=0;

  dREC04RECNUMTYP dNumBlocks = 0;

  // is it layer or block??
  if (this->sActLayBlkNam.length() > 0)
  {  // Block
    dNumBlocks = this->oSstFncBlk.count();
    oDxfCircle.setBlockID(dNumBlocks);
  }
  else
  {  // Layer
    oLayerStr = attributes.getLayer();
    if (oLayerStr.length() <= 0) return -2;  // Empty Layername not allowed

    // Find record with exact search value
    iStat = this->oSstFncLay.TreSeaEQ( 0, this->oSstFncLay.getNameSortKey(), (void*) oLayerStr.c_str(), &dLayRecNo);
    // assert(iStat == 1);
    if ( iStat != 1) return -3;  // Layername not found in layer table
    oDxfCircle.setLayerID(dLayRecNo);
  }
  iStat = this->oSstFncCircle.WritNew(0,&oDxfCircle, dEntRecNo);

  sstDxf03TypMainCls oMainRec;

  *dMainRecNo = this->oSstFncMain.count();

  oMainRec.setMainID( *dMainRecNo+1);
  oMainRec.setEntityType(RS2::EntityCircle);
  oMainRec.setTypeID(*dEntRecNo);

  // is it layer or block??
  if (this->sActLayBlkNam.length() > 0)
  {  // Block
    oMainRec.setLayBlockID(dNumBlocks);
    oMainRec.setSectString("B");
  }
  else
  {  // Layer
    oMainRec.setLayBlockID(dLayRecNo);
    oMainRec.setSectString("L");
  }
  iStat = this->oSstFncMain.WritNew(0,&oMainRec, dMainRecNo);
//     this->poPrt->SST_PrtWrtChar( 1,(char*)"CIRCLE skiped",(char*)"Dxf Reading: ");
  return 0;
}
//=============================================================================
int sstDxf03DatabaseCls::WriteCircle (int                  iKey,
                                      const DL_CircleData  data,
                                      const DL_Attributes  attributes,
                                      dREC04RECNUMTYP     *dEntRecNo,
                                      dREC04RECNUMTYP     *dMainRecNo)
//-----------------------------------------------------------------------------
{
  if ( iKey != 0) return -1;

  int iStat = 0;
  std::string oLayerStr;

  sstDxf03TypCircleCls oDxfCircle;
  oDxfCircle.ReadFromDL(data);
  oDxfCircle.BaseReadFromDL(attributes);
  dREC04RECNUMTYP dLayRecNo=0;

  dREC04RECNUMTYP dNumBlocks = 0;

  if (*dEntRecNo > 0)
  {
    // Existing Line
    oDxfCircle.ReadFromDL(data);
    oDxfCircle.BaseReadFromDL(attributes);
    iStat = this->oSstFncCircle.Writ( 0, &oDxfCircle, *dEntRecNo);
    // oLine.BaseWritToDL(oDLAttributes);
    return iStat;
  }

  // New Line

  // is it layer or block??
  if (this->sActLayBlkNam.length() > 0)
  {  // Block
    dNumBlocks = this->oSstFncBlk.count();
    oDxfCircle.setBlockID(dNumBlocks);
  }
  else
  {  // Layer
    oLayerStr = attributes.getLayer();
    if (oLayerStr.length() <= 0) return -2;  // Empty Layername not allowed

    // Find record with exact search value
    iStat = this->oSstFncLay.TreSeaEQ( 0, this->oSstFncLay.getNameSortKey(), (void*) oLayerStr.c_str(), &dLayRecNo);
    // assert(iStat == 1);
    if ( iStat != 1) return -3;  // Layername not found in layer table
    oDxfCircle.setLayerID(dLayRecNo);
  }
  iStat = this->oSstFncCircle.WritNew(0,&oDxfCircle, dEntRecNo);

  sstDxf03TypMainCls oMainRec;

  *dMainRecNo = this->oSstFncMain.count();

  oMainRec.setMainID( *dMainRecNo+1);
  oMainRec.setEntityType(RS2::EntityLine);
  oMainRec.setTypeID(*dEntRecNo);

  // is it layer or block??
  if (this->sActLayBlkNam.length() > 0)
  {  // Block
    oMainRec.setLayBlockID(dNumBlocks);
    oMainRec.setSectString("B");
  }
  else
  {  // Layer
    oMainRec.setLayBlockID(dLayRecNo);
    oMainRec.setSectString("L");
  }
  iStat = this->oSstFncMain.WritNew(0,&oMainRec, dMainRecNo);
  return 0;
}
//=============================================================================
int sstDxf03DatabaseCls::WritePoint (int                  iKey,
                                     const DL_PointData   data,
                                     const DL_Attributes  attributes,
                                     dREC04RECNUMTYP     *dEntRecNo,
                                     dREC04RECNUMTYP     *dMainRecNo)
//-----------------------------------------------------------------------------
{
  if ( iKey != 0) return -1;

  int iStat = 0;
  std::string oLayerStr;

  sstDxf03TypPointCls oDxfPoint;
  oDxfPoint.ReadFromDL(data);
  oDxfPoint.BaseReadFromDL(attributes);
  dREC04RECNUMTYP dLayRecNo=0;

  dREC04RECNUMTYP dNumBlocks = 0;

  if (*dEntRecNo > 0)
  {
    // Existing Line
    oDxfPoint.ReadFromDL(data);
    oDxfPoint.BaseReadFromDL(attributes);
    iStat = this->oSstFncPoint.Writ( 0, &oDxfPoint, *dEntRecNo);
    // oLine.BaseWritToDL(oDLAttributes);
    return iStat;
  }

  // New Line

  // is it layer or block??
  if (this->sActLayBlkNam.length() > 0)
  {  // Block
    dNumBlocks = this->oSstFncBlk.count();
    oDxfPoint.setBlockID(dNumBlocks);
  }
  else
  {  // Layer
    oLayerStr = attributes.getLayer();
    if (oLayerStr.length() <= 0) return -2;  // Empty Layername not allowed

    // Find record with exact search value
    iStat = this->oSstFncLay.TreSeaEQ( 0, this->oSstFncLay.getNameSortKey(), (void*) oLayerStr.c_str(), &dLayRecNo);
    // assert(iStat == 1);
    if ( iStat != 1) return -3;  // Layername not found in layer table
    oDxfPoint.setLayerID(dLayRecNo);
  }
  iStat = this->oSstFncPoint.WritNew(0,&oDxfPoint, dEntRecNo);

  sstDxf03TypMainCls oMainRec;

  *dMainRecNo = this->oSstFncMain.count();

  oMainRec.setMainID( *dMainRecNo+1);
  oMainRec.setEntityType(RS2::EntityLine);
  oMainRec.setTypeID(*dEntRecNo);

  // is it layer or block??
  if (this->sActLayBlkNam.length() > 0)
  {  // Block
    oMainRec.setLayBlockID(dNumBlocks);
    oMainRec.setSectString("B");
  }
  else
  {  // Layer
    oMainRec.setLayBlockID(dLayRecNo);
    oMainRec.setSectString("L");
  }
  iStat = this->oSstFncMain.WritNew(0,&oMainRec, dMainRecNo);
  return 0;
}
//=============================================================================
int sstDxf03DatabaseCls::WriteLine (int                  iKey,
                                    const DL_LineData  data,
                                    const DL_Attributes  attributes,
                                    dREC04RECNUMTYP     *dEntRecNo,
                                    dREC04RECNUMTYP     *dMainRecNo)
//-----------------------------------------------------------------------------
{
  if ( iKey != 0) return -1;

  int iStat = 0;
  std::string oLayerStr;

  sstDxf03TypLineCls oDxfLine;
  oDxfLine.ReadFromDL(data);
  oDxfLine.BaseReadFromDL(attributes);
  dREC04RECNUMTYP dLayRecNo=0;

  dREC04RECNUMTYP dNumBlocks = 0;

  if (*dEntRecNo > 0)
  {
    // Existing Line
    oDxfLine.ReadFromDL(data);
    oDxfLine.BaseReadFromDL(attributes);
    iStat = this->oSstFncLine.Writ( 0, &oDxfLine, *dEntRecNo);
    // oLine.BaseWritToDL(oDLAttributes);
    return iStat;
  }

  // New Line

  // is it layer or block??
  if (this->sActLayBlkNam.length() > 0)
  {  // Block
    dNumBlocks = this->oSstFncBlk.count();
    oDxfLine.setBlockID(dNumBlocks);
  }
  else
  {  // Layer
    oLayerStr = attributes.getLayer();
    if (oLayerStr.length() <= 0) return -2;  // Empty Layername not allowed

    // Find record with exact search value
    iStat = this->oSstFncLay.TreSeaEQ( 0, this->oSstFncLay.getNameSortKey(), (void*) oLayerStr.c_str(), &dLayRecNo);
    // assert(iStat == 1);
    if ( iStat != 1) return -3;  // Layername not found in layer table
    oDxfLine.setLayerID(dLayRecNo);
  }
  iStat = this->oSstFncLine.WritNew(0,&oDxfLine, dEntRecNo);

  sstDxf03TypMainCls oMainRec;

  *dMainRecNo = this->oSstFncMain.count();

  oMainRec.setMainID( *dMainRecNo+1);
  oMainRec.setEntityType(RS2::EntityLine);
  oMainRec.setTypeID(*dEntRecNo);

  // is it layer or block??
  if (this->sActLayBlkNam.length() > 0)
  {  // Block
    oMainRec.setLayBlockID(dNumBlocks);
    oMainRec.setSectString("B");
  }
  else
  {  // Layer
    oMainRec.setLayBlockID(dLayRecNo);
    oMainRec.setSectString("L");
  }
  iStat = this->oSstFncMain.WritNew(0,&oMainRec, dMainRecNo);
  return 0;
}
//=============================================================================
int sstDxf03DatabaseCls::WriteMText (int                  iKey,
                                    const DL_MTextData  data,
                                    const DL_Attributes  attributes,
                                    dREC04RECNUMTYP     *dEntRecNo,
                                    dREC04RECNUMTYP     *dMainRecNo)
//-----------------------------------------------------------------------------
{
  if ( iKey != 0) return -1;

  int iStat = 0;
  std::string oLayerStr;

  sstDxf03TypMTextCls oDxfMText;
  oDxfMText.ReadFromDL(data);
  oDxfMText.BaseReadFromDL(attributes);
  dREC04RECNUMTYP dLayRecNo=0;

  dREC04RECNUMTYP dNumBlocks = 0;

  if (*dEntRecNo > 0)
  {
    // Existing Line
    oDxfMText.ReadFromDL(data);
    oDxfMText.BaseReadFromDL(attributes);
    iStat = this->oSstFncMText.Writ( 0, &oDxfMText, *dEntRecNo);
    // oLine.BaseWritToDL(oDLAttributes);
    return iStat;
  }

  // New Line

  // is it layer or block??
  if (this->sActLayBlkNam.length() > 0)
  {  // Block
    dNumBlocks = this->oSstFncBlk.count();
    oDxfMText.setBlockID(dNumBlocks);
  }
  else
  {  // Layer
    oLayerStr = attributes.getLayer();
    if (oLayerStr.length() <= 0) return -2;  // Empty Layername not allowed

    // Find record with exact search value
    iStat = this->oSstFncLay.TreSeaEQ( 0, this->oSstFncLay.getNameSortKey(), (void*) oLayerStr.c_str(), &dLayRecNo);
    // assert(iStat == 1);
    if ( iStat != 1) return -3;  // Layername not found in layer table
    oDxfMText.setLayerID(dLayRecNo);
  }
  iStat = this->oSstFncMText.WritNew(0,&oDxfMText, dEntRecNo);

  sstDxf03TypMainCls oMainRec;

  *dMainRecNo = this->oSstFncMain.count();

  oMainRec.setMainID( *dMainRecNo+1);
  oMainRec.setEntityType(RS2::EntityLine);
  oMainRec.setTypeID(*dEntRecNo);

  // is it layer or block??
  if (this->sActLayBlkNam.length() > 0)
  {  // Block
    oMainRec.setLayBlockID(dNumBlocks);
    oMainRec.setSectString("B");
  }
  else
  {  // Layer
    oMainRec.setLayBlockID(dLayRecNo);
    oMainRec.setSectString("L");
  }
  iStat = this->oSstFncMain.WritNew(0,&oMainRec, dMainRecNo);
  return 0;
}
//==============================================================================
int sstDxf03DatabaseCls::WriteText (int                  iKey,
                                    const DL_TextData  data,
                                    const DL_Attributes  attributes,
                                    dREC04RECNUMTYP     *dEntRecNo,
                                    dREC04RECNUMTYP     *dMainRecNo)
//-----------------------------------------------------------------------------
{
  if ( iKey != 0) return -1;

  int iStat = 0;
  std::string oLayerStr;

  sstDxf03TypTextCls oDxfText;
  oDxfText.ReadFromDL(data);
  oDxfText.BaseReadFromDL(attributes);
  dREC04RECNUMTYP dLayRecNo=0;

  dREC04RECNUMTYP dNumBlocks = 0;

  if (*dEntRecNo > 0)
  {
    // Existing Line
    oDxfText.ReadFromDL(data);
    oDxfText.BaseReadFromDL(attributes);
    iStat = this->oSstFncText.Writ( 0, &oDxfText, *dEntRecNo);
    // oLine.BaseWritToDL(oDLAttributes);
    return iStat;
  }

  // New Line

  // is it layer or block??
  if (this->sActLayBlkNam.length() > 0)
  {  // Block
    dNumBlocks = this->oSstFncBlk.count();
    oDxfText.setBlockID(dNumBlocks);
  }
  else
  {  // Layer
    oLayerStr = attributes.getLayer();
    if (oLayerStr.length() <= 0) return -2;  // Empty Layername not allowed

    // Find record with exact search value
    iStat = this->oSstFncLay.TreSeaEQ( 0, this->oSstFncLay.getNameSortKey(), (void*) oLayerStr.c_str(), &dLayRecNo);
    // assert(iStat == 1);
    if ( iStat != 1) return -3;  // Layername not found in layer table
    oDxfText.setLayerID(dLayRecNo);
  }
  iStat = this->oSstFncText.WritNew(0,&oDxfText, dEntRecNo);

  sstDxf03TypMainCls oMainRec;

  *dMainRecNo = this->oSstFncMain.count();

  oMainRec.setMainID( *dMainRecNo+1);
  oMainRec.setEntityType(RS2::EntityLine);
  oMainRec.setTypeID(*dEntRecNo);

  // is it layer or block??
  if (this->sActLayBlkNam.length() > 0)
  {  // Block
    oMainRec.setLayBlockID(dNumBlocks);
    oMainRec.setSectString("B");
  }
  else
  {  // Layer
    oMainRec.setLayBlockID(dLayRecNo);
    oMainRec.setSectString("L");
  }
  iStat = this->oSstFncMain.WritNew(0,&oMainRec, dMainRecNo);
  return 0;
}
//==============================================================================
int sstDxf03DatabaseCls::OpenNewHatch(int                  iKey,
                                      const DL_HatchData   oDLHatch,
                                      const DL_Attributes  oDLAttributes,
                                      dREC04RECNUMTYP     *oEntRecNo,
                                      dREC04RECNUMTYP     *oMainRecNo)
//-----------------------------------------------------------------------------
{
  if ( iKey != 0) return -1;

  int iStat = 0;
  std::string oLayerStr;

  sstDxf03TypHatchCls oDxfHatch;
  oDxfHatch.ReadFromDL(oDLHatch);
  oDxfHatch.BaseReadFromDL(oDLAttributes);

  // dREC04RECNUMTYP dEntRecNo=0;
  dREC04RECNUMTYP dLayRecNo=0;
  dREC04RECNUMTYP dLTypeRecNo=0;

  sstDxf03FncHatchCls *poHatchFnc;
  poHatchFnc = this->getSstFncHatch();
  sstDxf03FncLayCls *poLayFnc;
  poLayFnc = this->getSstFncLay();
  sstDxf03FncBlkCls *poBlkFnc;
  poBlkFnc = this->getSstFncBlk();
  sstDxf03FncMainCls *poMainFnc;
  poMainFnc = this->getSstFncMain();

  dREC04RECNUMTYP dNumBlocks = 0;

  // is it layer or block??
  if (this->sActLayBlkNam.length() > 0)
  {  // Block
    dNumBlocks = poBlkFnc->count();
    oDxfHatch.setBlockID(dNumBlocks);
  }
  else
  {  // Layer
    oLayerStr = oDLAttributes.getLayer();
    // Find record with exact search value
    iStat = poLayFnc->TreSeaEQ( 0, poLayFnc->getNameSortKey(), (void*) oLayerStr.c_str(), &dLayRecNo);
    assert(iStat == 1);
    oDxfHatch.setLayerID(dLayRecNo);
  }

  sstDxf03FncLTypeCls *poLTypeFnc;
  poLTypeFnc = this->getSstFncLType();

  std::string oLTypeStr;
  oLTypeStr = oDLAttributes.getLinetype();

  std::transform(oLTypeStr.begin(), oLTypeStr.end(),oLTypeStr.begin(), ::toupper);

  // Find record with exact search value
  iStat = poLTypeFnc->TreSeaEQ( 0, poLTypeFnc->getNameSortKey(), (void*) oLTypeStr.c_str(), &dLTypeRecNo);
  assert(iStat == 1);
  oDxfHatch.setLinetypeID(dLTypeRecNo);

  // iStat = poHatchFnc->WritNew(0,&oDxfHatch,&dEntRecNo);
  iStat = poHatchFnc->WritNew( 0, &oDxfHatch, oEntRecNo);
  assert(iStat == 0);

  sstDxf03TypMainCls oMainRec;

  dREC04RECNUMTYP dMainRecNo = poMainFnc->count();

  oMainRec.setMainID(dMainRecNo+1);
  oMainRec.setEntityType(RS2::EntityHatch);
  oMainRec.setTypeID(*oEntRecNo);

  // is it layer or block??
  if (this->sActLayBlkNam.length() > 0)
  {  // Block
    oMainRec.setLayBlockID(dNumBlocks);
    oMainRec.setSectString("B");
  }
  else
  {  // Layer
    oMainRec.setLayBlockID(dLayRecNo);
    oMainRec.setSectString("L");
  }
  iStat = poMainFnc->WritNew(0,&oMainRec, oMainRecNo);
  assert(iStat == 0);

  this->dGrpMainID = *oMainRecNo;
  this->eGrpEntType = RS2::EntityHatch;
  this->dGrpSubID = 0;              // Sub Group ID like HatchLoop
  this->dGrpRecNum = 0;

  this->setMainTabSectEntStart(*oEntRecNo);
  return iStat;
}
//==============================================================================
int sstDxf03DatabaseCls::WriteNewHatchEdge (int                    iKey,
                                            const DL_HatchEdgeData oDLHatchEdge,
                                            dREC04RECNUMTYP       *oEntRecNo,
                                            dREC04RECNUMTYP       *oMainRecNo)
//-----------------------------------------------------------------------------
{
  if ( iKey != 0) return -1;

  //--- Write HatchLoop
  int iStat = 0;
  std::string oLayerStr;
  dREC04RECNUMTYP dLayRecNo=0;
  dREC04RECNUMTYP dNumBlocks = 0;
  dREC04RECNUMTYP dTmpMainRecNo = 0;

  sstDxf03FncMainCls *poMainFnc;
  poMainFnc = this->getSstFncMain();

  sstDxf03TypMainCls oMainRec;

  sstDxf03TypHatchLoopCls oDxfHatchLoop;
  sstDxf03FncHatchLoopCls *poHatchLoopFnc;
  poHatchLoopFnc = this->getSstFncHatchLoop();

  if (this->dGrpSubID == 0)
  { // Start new sup group HatchLoop

    DL_HatchLoopData oDLHatchLoop;

    oDLHatchLoop.numEdges = 1;

    oDxfHatchLoop.ReadFromDL(oDLHatchLoop);
    // dREC04RECNUMTYP dRecNo=0;



    iStat = poHatchLoopFnc->WritNew(0,&oDxfHatchLoop,oEntRecNo);
    assert (iStat == 0);


    dTmpMainRecNo = poMainFnc->count();

    oMainRec.setMainID(dTmpMainRecNo+1);
    oMainRec.setEntityType(RS2::EntityHatchLoop);
    oMainRec.setTypeID(*oEntRecNo);

    // is it layer or block??
    if (this->sActLayBlkNam.length() > 0)
    {  // Block
      oMainRec.setLayBlockID(dNumBlocks);
      oMainRec.setSectString("B");
    }
    else
    {  // Layer
      oMainRec.setLayBlockID(dLayRecNo);
      oMainRec.setSectString("L");
    }
    iStat = poMainFnc->WritNew(0,&oMainRec, oMainRecNo);
    assert (iStat == 0);

    this->dGrpSubID = *oEntRecNo;
    //-----------------------------------------------------------------------------
  }
  else
  {
    // next edge for actual loop
    iStat = poHatchLoopFnc->Read(0, this->dGrpSubID, &oDxfHatchLoop);
    oDxfHatchLoop.setNumEdges(oDxfHatchLoop.getNumEdges()+1);  // update number of edges
    iStat = poHatchLoopFnc->WritNew(0,&oDxfHatchLoop,oEntRecNo);
    assert (iStat == 0);
  }

  //--- Write HatchEdge

  // std::string oLayerStr;
  oLayerStr.clear();

  sstDxf03TypHatchEdgeCls oDxfHatchEdge;
  oDxfHatchEdge.ReadFromDL(oDLHatchEdge);
  // oDxfArc.BaseReadFromDL(attributes);
  // dRecNo = 0;
  dLayRecNo = 0;

  sstDxf03FncHatchEdgeCls *poHatchEdgeFnc;
  poHatchEdgeFnc = this->getSstFncHatchEdge();
  // sstDxf03FncMainCls *poMainFnc;
  // poMainFnc = this->getSstFncMain();

  dNumBlocks = 0;

  oDxfHatchEdge.setParentID(this->getMainTabSectEntStart());

  // iStat = poHatchEdgeFnc->WritNew(0,&oDxfHatchEdge,&dRecNo);
  iStat = poHatchEdgeFnc->WritNew(0,&oDxfHatchEdge, oEntRecNo);
  assert(iStat == 0);

  // sstDxf03TypMainCls oMainRec;

  dTmpMainRecNo = poMainFnc->count();

  oMainRec.setMainID(dTmpMainRecNo+1);
  oMainRec.setEntityType(RS2::EntityHatchEdge);
  oMainRec.setTypeID(*oEntRecNo);

  // is it layer or block??
  if (this->sActLayBlkNam.length() > 0)
  {  // Block
    oMainRec.setLayBlockID(dNumBlocks);
    oMainRec.setSectString("B");
  }
  else
  {  // Layer
    oMainRec.setLayBlockID(dLayRecNo);
    oMainRec.setSectString("L");
  }
  // iStat = poMainFnc->WritNew(0,&oMainRec,&dRecNo);
  iStat = poMainFnc->WritNew(0,&oMainRec, oMainRecNo);
  assert(iStat == 0);
  return iStat;
}
//==============================================================================
int sstDxf03DatabaseCls::WritAll2DxfFil(int iKey, const std::string oDxfFilNam)
{

  if ( iKey != 0) return -1;

  int iStat = 0;

  sstDxf03WriteCls oWrite( this, this->GetPrtAdr());

  if (iStat >= 0) iStat = oWrite.OpenNewDxfFile(0,oDxfFilNam);  // Open dxf file for writing data
  if (iStat >= 0) iStat = oWrite.WrtSecHeader(0);    // write header section to dxf file
  if (iStat >= 0) iStat = oWrite.WrtSecTypes(0);     // write types section to dxf file
  if (iStat >= 0) iStat = oWrite.WrtSecLayers(0);    // write layer section to dxf file
  if (iStat >= 0) iStat = oWrite.WrtSecStyles(0);    // write styles section to dxf file
  if (iStat >= 0) iStat = oWrite.WrtSecBlocks(0);    // write blocks section to dxf file
  if (iStat >= 0) iStat = oWrite.WrtSecEntities(0);  // write entities section to dxf file
  if (iStat >= 0) iStat = oWrite.WrtSecObjects(0);   // write objects section to dxf file

  // this->oPrt->SST_PrtWrtInt4(1,this->MainCount(),(char*)"Number of Main Data written: ");

  // Write Import Statistics to protocol
  this->oPrt->SST_PrtWrtInt4(1,this->MainCount(),(char*)"Number of Data read: ");
  this->oPrt->SST_PrtWrtInt4(1,this->EntityCount(RS2::EntityArc),(char*)"Number of ARC entities: ");
  this->oPrt->SST_PrtWrtInt4(1,this->EntityCount(RS2::EntityCircle),(char*)"Number of CIRCLE entities: ");
  this->oPrt->SST_PrtWrtInt4(1,this->EntityCount(RS2::EntityLine),(char*)"Number of LINE entities: ");
  this->oPrt->SST_PrtWrtInt4(1,this->EntityCount(RS2::EntityPolyline),(char*)"Number of POLYLINE entities: ");
  this->oPrt->SST_PrtWrtInt4(1,this->EntityCount(RS2::EntityHatch),(char*)"Number of HATCH entities: ");
  this->oPrt->SST_PrtWrtInt4(1,this->EntityCount(RS2::EntityHatchLoop),(char*)"Number of HATCHLOOP entities: ");
  this->oPrt->SST_PrtWrtInt4(1,this->EntityCount(RS2::EntityHatchEdge),(char*)"Number of HATCHEDGE entities: ");
  this->oPrt->SST_PrtWrtInt4(1,this->EntityCount(RS2::EntityInsert),(char*)"Number of INSERT entities: ");
  this->oPrt->SST_PrtWrtInt4(1,this->EntityCount(RS2::EntityMText),(char*)"Number of MTEXT entities: ");
  this->oPrt->SST_PrtWrtInt4(1,this->EntityCount(RS2::EntityText),(char*)"Number of TEXT entities: ");
  this->oPrt->SST_PrtWrtInt4(1,this->EntityCount(RS2::EntityPoint),(char*)"Number of POINT entities: ");
  this->oPrt->SST_PrtWrtInt4(1,this->EntityCount(RS2::EntityVertex),(char*)"Number of VERTEX entities: ");

  this->oPrt->SST_PrtWrtChar(1,(char*)oDxfFilNam.c_str(),(char*)"Dxf Database to File written: ");

  return iStat;
}
//==============================================================================
int sstDxf03DatabaseCls::WritAll2Csv(int iKey, const std::string oTmpFilNam)
{
  if ( iKey != 0) return -1;

  int iStat = 0;

  std::string oDxfFilNam;
  sstMisc01FilNamCls oFilNamHelper;
  oFilNamHelper.RemoveExtension(0,"dxf",oTmpFilNam,&oDxfFilNam);

  std::string oCsvStr;

    sstMisc01AscFilCls oCsvFil;
    std::string oCsvFilNam;

    sstDxf03FncArcCls *poArcFnc;
    poArcFnc = this->getSstFncArc();

    sstDxf03FncInsertCls *poInsertFnc;
    poInsertFnc = this->getSstFncInsert();

    sstDxf03FncPolylineCls *poPolylineFnc;
    poPolylineFnc = this->getSstFncPolyline();

    sstDxf03FncHatchCls *poHatchFnc;
    poHatchFnc = this->getSstFncHatch();

    sstDxf03FncHatchEdgeCls *poHatchEdgeFnc;
    poHatchEdgeFnc = this->getSstFncHatchEdge();

    sstDxf03FncHatchLoopCls *poHatchLoopFnc;
    poHatchLoopFnc = this->getSstFncHatchLoop();

    sstDxf03FncVertexCls *poVertexFnc;
    poVertexFnc = this->getSstFncVertex();

    sstDxf03FncCircleCls *poCircleFnc;
    poCircleFnc = this->getSstFncCircle();

    sstDxf03FncMTextCls *poMTextFnc;
    poMTextFnc = this->getSstFncMText();

    sstDxf03FncTextCls *poTextFnc;
    poTextFnc = this->getSstFncText();

    sstDxf03FncPointCls *poPointFnc;
    poPointFnc = this->getSstFncPoint();

    sstDxf03FncLineCls *poLineFnc;
    poLineFnc = this->getSstFncLine();

    sstDxf03FncLayCls *poLayFnc;
    poLayFnc = this->getSstFncLay();

    sstDxf03FncBlkCls *poBlkFnc;
    poBlkFnc = this->getSstFncBlk();

    sstDxf03FncLTypeCls *poLTypeFnc;
    poLTypeFnc = this->getSstFncLType();

    sstDxf03FncMainCls *poMainFnc;
    poMainFnc = this->getSstFncMain();

    // write all arc data from table to csv file
    iStat = poArcFnc->WriteCsvFile( 0,  oDxfFilNam);
    assert(iStat == 0);

    // write all insert data from table to csv file
    iStat = poInsertFnc->WriteCsvFile( 0, oDxfFilNam);
    assert(iStat == 0);

    // write all polyline data from table to csv file
    iStat = poPolylineFnc->WriteCsvFile( 0, oDxfFilNam);
    assert(iStat == 0);

    // write all hatch data from table to csv file
    iStat = poHatchFnc->WriteCsvFile( 0, oDxfFilNam);
    assert(iStat == 0);

    // write all hatch loop data from table to csv file
    iStat = poHatchLoopFnc->WriteCsvFile( 0, oDxfFilNam);
    assert(iStat == 0);

    // write all hatch edge data from table to csv file
    iStat = poHatchEdgeFnc->WriteCsvFile( 0, oDxfFilNam);
    assert(iStat == 0);

    // write all vertex data from table to csv file
    iStat = poVertexFnc->WriteCsvFile( 0, oDxfFilNam);
    assert(iStat == 0);

    // write all Circle data from table to csv file
    iStat = poCircleFnc->WriteCsvFile( 0, oDxfFilNam);
    assert(iStat == 0);

    // write all MText data from table to csv file
    iStat = poMTextFnc->WriteCsvFile( 0, oDxfFilNam);
    assert(iStat == 0);

    // write all Text data from table to csv file
    iStat = poTextFnc->WriteCsvFile( 0, oDxfFilNam);
    assert(iStat == 0);

    // write all point data from table to csv file
    iStat = poPointFnc->WriteCsvFile( 0, oDxfFilNam);
    assert(iStat == 0);

    // write all line data from table to csv file
    iStat = poLineFnc->WriteCsvFile( 0, oDxfFilNam);
    assert(iStat == 0);

    // write all layer data from table to csv file
    iStat = poLayFnc->WriteCsvFile( 0, oDxfFilNam);
    assert(iStat == 0);

    // write all block data from table to csv file
    iStat = poBlkFnc->WriteCsvFile( 0, oDxfFilNam);
    assert(iStat == 0);

    // write all Linetype data from table to csv file
    iStat = poLTypeFnc->WriteCsvFile( 0, oDxfFilNam);
    assert(iStat == 0);

    // write all main data from table to csv file
    iStat = poMainFnc->WriteCsvFile( 0, oDxfFilNam);
    assert(iStat == 0);

  return 0;
}
//=============================================================================
sstMisc01PrtFilCls* sstDxf03DatabaseCls::GetPrtAdr()
{
  return this->oPrt;
}
//=============================================================================
int sstDxf03DatabaseCls::ReadAllFromDxf(int iKey, const std::string oDxfFilNam)
{
  if ( iKey != 0) return -1;
  int iStat = 0;

  this->oPrt->SST_PrtWrtChar(1,(char*) oDxfFilNam.c_str(), (char*)"Reading file: ");
  sstDxf03ReadCls* creationClass = new sstDxf03ReadCls( this, this->GetPrtAdr());

  creationClass->SetDxfFilNam((char*) oDxfFilNam.c_str());

  DL_Dxf* dxf = new DL_Dxf();
  if (!dxf->in(oDxfFilNam, creationClass))
  { // if file open failed
    this->oPrt->SST_PrtWrtChar(1,(char*) oDxfFilNam.c_str(),(char*)"Error: Could not open: ");
    iStat = -2;
  }

  // Write Import Statistics to protocol
  this->oPrt->SST_PrtWrtInt4(1,this->MainCount(),(char*)"Number of Data read: ");
  this->oPrt->SST_PrtWrtInt4(1,this->EntityCount(RS2::EntityArc),(char*)"Number of ARC entities: ");
  this->oPrt->SST_PrtWrtInt4(1,this->EntityCount(RS2::EntityCircle),(char*)"Number of CIRCLE entities: ");
  this->oPrt->SST_PrtWrtInt4(1,this->EntityCount(RS2::EntityLine),(char*)"Number of LINE entities: ");
  this->oPrt->SST_PrtWrtInt4(1,this->EntityCount(RS2::EntityPolyline),(char*)"Number of POLYLINE entities: ");
  this->oPrt->SST_PrtWrtInt4(1,this->EntityCount(RS2::EntityHatch),(char*)"Number of HATCH entities: ");
  this->oPrt->SST_PrtWrtInt4(1,this->EntityCount(RS2::EntityHatchLoop),(char*)"Number of HATCHLOOP entities: ");
  this->oPrt->SST_PrtWrtInt4(1,this->EntityCount(RS2::EntityHatchEdge),(char*)"Number of HATCHEDGE entities: ");
  this->oPrt->SST_PrtWrtInt4(1,this->EntityCount(RS2::EntityInsert),(char*)"Number of INSERT entities: ");
  this->oPrt->SST_PrtWrtInt4(1,this->EntityCount(RS2::EntityMText),(char*)"Number of MTEXT entities: ");
  this->oPrt->SST_PrtWrtInt4(1,this->EntityCount(RS2::EntityText),(char*)"Number of TEXT entities: ");
  this->oPrt->SST_PrtWrtInt4(1,this->EntityCount(RS2::EntityPoint),(char*)"Number of POINT entities: ");
  this->oPrt->SST_PrtWrtInt4(1,this->EntityCount(RS2::EntityVertex),(char*)"Number of VERTEX entities: ");

  delete dxf;
  delete creationClass;

  // Update all Trees?

  return iStat;
}
//=============================================================================
dREC04RECNUMTYP sstDxf03DatabaseCls::MainCount()
{
  return this->oSstFncMain.count();
}
//=============================================================================
dREC04RECNUMTYP sstDxf03DatabaseCls::EntityCount(RS2::EntityType eEntityType)
{
  dREC04RECNUMTYP dTmpCount = 0;

  switch (eEntityType)
  {
  case RS2::EntityArc:
    dTmpCount = this->oSstFncArc.count();
    break;
  case RS2::EntityCircle:
    dTmpCount = this->oSstFncCircle.count();
    break;
  case RS2::EntityLine:
    dTmpCount = this->oSstFncLine.count();
    break;
  case RS2::EntityInsert:
    dTmpCount = this->oSstFncInsert.count();
    break;
  case RS2::EntityPolyline:
    dTmpCount = this->oSstFncPolyline.count();
    break;
  case RS2::EntityMText:
    dTmpCount = this->oSstFncMText.count();
    break;
  case RS2::EntityPoint:
    dTmpCount = this->oSstFncPoint.count();
    break;
  case RS2::EntityText:
    dTmpCount = this->oSstFncText.count();
    break;
  case RS2::EntityHatch:
    dTmpCount = this->oSstFncHatch.count();
    break;
  case RS2::EntityHatchLoop:
    dTmpCount = this->oSstFncHatchLoop.count();
    break;
  case RS2::EntityHatchEdge:
    dTmpCount = this->oSstFncHatchEdge.count();
    break;
  case RS2::EntityVertex:
    dTmpCount = this->oSstFncVertex.count();
    break;
  default:
    assert(0);
    break;
  }
  return dTmpCount;
}
//=============================================================================
int sstDxf03DatabaseCls::ColumnCount(RS2::EntityType eEntityType)
{
  dREC04RECNUMTYP dTmpCount = 0;

  switch (eEntityType)
  {
  case RS2::EntityArc:
  {
    sstDxf03TypArcCls oTypeRec;
    dTmpCount = oTypeRec.getMemberNumber();
    break;
  }
  case RS2::EntityCircle:
  {
    sstDxf03TypCircleCls oTypeRec;
    dTmpCount = oTypeRec.getMemberNumber();
    break;
  }
  case RS2::EntityLine:
  {
    sstDxf03TypLineCls oTypeRec;
    dTmpCount = oTypeRec.getMemberNumber();
    break;
  }
  case RS2::EntityInsert:
  {
    sstDxf03TypInsertCls oTypeRec;
    dTmpCount = oTypeRec.getMemberNumber();
    break;
  }
  case RS2::EntityPolyline:
  {
    sstDxf03TypPolylineCls oTypeRec;
    dTmpCount = oTypeRec.getMemberNumber();
    break;
  }
  case RS2::EntityMText:
  {
    sstDxf03TypMTextCls oTypeRec;
    dTmpCount = oTypeRec.getMemberNumber();
    break;
  }
  case RS2::EntityPoint:
  {
    sstDxf03TypPointCls oTypeRec;
    dTmpCount = oTypeRec.getMemberNumber();
    break;
  }
  case RS2::EntityText:
  {
    sstDxf03TypTextCls oTypeRec;
    dTmpCount = oTypeRec.getMemberNumber();
    break;
  }
  case RS2::EntityHatch:
  {
    sstDxf03TypHatchCls oTypeRec;
    dTmpCount = oTypeRec.getMemberNumber();
    break;
  }
  case RS2::EntityHatchLoop:
  {
    sstDxf03TypHatchLoopCls oTypeRec;
    dTmpCount = oTypeRec.getMemberNumber();
    break;
  }
  case RS2::EntityHatchEdge:
  {
    sstDxf03TypHatchEdgeCls oTypeRec;
    dTmpCount = oTypeRec.getMemberNumber();
    break;
  }
  case RS2::EntityVertex:
  {
    sstDxf03TypVertexCls oTypeRec;
    dTmpCount = oTypeRec.getMemberNumber();
    break;
  }
  default:
    assert(0);
    break;
  }
  return dTmpCount;
}
//=============================================================================
int sstDxf03DatabaseCls::ReadHatch ( int iKey, dREC04RECNUMTYP dRecNo, DL_HatchData *oDLHatch, DL_Attributes *oDLAttributes)
{
  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  sstDxf03TypHatchCls oHatch;

  iStat = this->oSstFncHatch.Read(0,dRecNo,&oHatch);
  oHatch.BaseWritToDL(oDLAttributes);

  // Update DL Attributes with Layer/LType Identifier
  iStat = this->UpdateAttribWithId( 0, oHatch.getLayerID(), oHatch.getLinetypeID(), oDLAttributes);

  oHatch.WritToDL(oDLHatch);
  return iStat;
}
//=============================================================================
int sstDxf03DatabaseCls::ReadHatchEdge( int iKey, dREC04RECNUMTYP dRecNo, DL_HatchEdgeData *oDLHatchEdge)
{
  // int iRet  = 0;
  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  sstDxf03TypHatchEdgeCls oHatchEdge;

  iStat = this->oSstFncHatchEdge.Read(0,dRecNo,&oHatchEdge);
  oHatchEdge.WritToDL(oDLHatchEdge);

  return iStat;
}
//=============================================================================
int sstDxf03DatabaseCls::ReadHatchLoop( int iKey, dREC04RECNUMTYP dRecNo, DL_HatchLoopData *oDLHatchLoop)
{
  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  sstDxf03TypHatchLoopCls oHatchLoop;

  iStat = this->oSstFncHatchLoop.Read(0,dRecNo,&oHatchLoop);
  oHatchLoop.WritToDL(oDLHatchLoop);

  return iStat;
}
//=============================================================================
int sstDxf03DatabaseCls::ReadCircle ( int iKey, dREC04RECNUMTYP dRecNo, DL_CircleData *oDLCircle, DL_Attributes *oDLAttributes)
{
  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  sstDxf03TypCircleCls oCircle;

  iStat = this->oSstFncCircle.Read(0,dRecNo,&oCircle);
  oCircle.BaseWritToDL(oDLAttributes);

  // Update DL Attributes with Layer/LType Identifier
  iStat = this->UpdateAttribWithId( 0, oCircle.getLayerID(), oCircle.getLinetypeID(), oDLAttributes);

  oCircle.WritToDL(oDLCircle);
  return iStat;
}
//=============================================================================
int sstDxf03DatabaseCls::ReadVertex ( int iKey, dREC04RECNUMTYP dRecNo, DL_VertexData *oDLVertex)
{
  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  sstDxf03TypVertexCls oVertex;

  iStat = this->oSstFncVertex.Read(0,dRecNo,&oVertex);
  // oVertex.BaseWritToDL(oDLAttributes);

  // Update DL Attributes with Layer/LType Identifier
  // iStat = this->UpdateAttribWithId( 0, oVertex.getLayerID(), oVertex.getLinetypeID(), oDLAttributes);

  oVertex.WritToDL(oDLVertex);
  return iStat;
}
//=============================================================================
int sstDxf03DatabaseCls::ReadLine ( int iKey, dREC04RECNUMTYP dRecNo, DL_LineData *oDLLine, DL_Attributes *oDLAttributes)
{
  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  sstDxf03TypLineCls oLine;

  iStat = this->oSstFncLine.Read(0,dRecNo,&oLine);
  oLine.BaseWritToDL(oDLAttributes);

  // Update DL Attributes with Layer/LType Identifier
  iStat = this->UpdateAttribWithId(0,oLine.getLayerID(),oLine.getLinetypeID(), oDLAttributes);

  oLine.WritToDL(oDLLine);
  return iStat;
}
//=============================================================================
int sstDxf03DatabaseCls::ReadPoint ( int iKey, dREC04RECNUMTYP dRecNo, DL_PointData *oDLPoint, DL_Attributes *oDLAttributes)
{
  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  sstDxf03TypPointCls oPoint;

  iStat = this->oSstFncPoint.Read(0,dRecNo,&oPoint);
  oPoint.BaseWritToDL(oDLAttributes);

  // Update DL Attributes with Layer/LType Identifier
  iStat = this->UpdateAttribWithId(0,oPoint.getLayerID(),oPoint.getLinetypeID(), oDLAttributes);

  oPoint.WritToDL(oDLPoint);
  return iStat;
}
//=============================================================================
int sstDxf03DatabaseCls::ReadMText ( int iKey, dREC04RECNUMTYP dRecNo, DL_MTextData *oDLMText, DL_Attributes *oDLAttributes)
{
  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  sstDxf03TypMTextCls oMText;

  iStat = this->oSstFncMText.Read(0,dRecNo,&oMText);
  oMText.BaseWritToDL(oDLAttributes);

  // Update DL Attributes with Layer/LType Identifier
  iStat = this->UpdateAttribWithId(0,oMText.getLayerID(),oMText.getLinetypeID(), oDLAttributes);

  oMText.WritToDL(oDLMText);
  return iStat;
}
//=============================================================================
int sstDxf03DatabaseCls::ReadText ( int iKey, dREC04RECNUMTYP dRecNo, DL_TextData *oDLText, DL_Attributes *oDLAttributes)
{
  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  sstDxf03TypTextCls oText;

  iStat = this->oSstFncText.Read(0,dRecNo,&oText);
  oText.BaseWritToDL(oDLAttributes);

  // Update DL Attributes with Layer/LType Identifier
  iStat = this->UpdateAttribWithId(0,oText.getLayerID(),oText.getLinetypeID(), oDLAttributes);

  oText.WritToDL(oDLText);
  return iStat;
}
//=============================================================================
int sstDxf03DatabaseCls::ReadPolyline ( int iKey, dREC04RECNUMTYP dRecNo, DL_PolylineData *oDLPolyline, DL_Attributes *oDLAttributes)
{
  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  sstDxf03TypPolylineCls oPolyline;

  iStat = this->oSstFncPolyline.Read(0,dRecNo,&oPolyline);
  oPolyline.BaseWritToDL(oDLAttributes);

  // Update DL Attributes with Layer/LType Identifier
  iStat = this->UpdateAttribWithId(0,oPolyline.getLayerID(),oPolyline.getLinetypeID(), oDLAttributes);

  oPolyline.WritToDL(oDLPolyline);
  return iStat;
}
//=============================================================================
int sstDxf03DatabaseCls::ReadBlock ( int iKey, dREC04RECNUMTYP dRecNo, DL_BlockData *oDLBlock, DL_Attributes *oDLAttributes)
{
  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  sstDxf03TypBlkCls oBlock;

  iStat = this->oSstFncBlk.Read(0,dRecNo,&oBlock);
  oBlock.BaseWritToDL(oDLAttributes);

  // Update DL Attributes with Layer/LType Identifier
  iStat = this->UpdateAttribWithId(0,oBlock.getLayerID(),oBlock.getLinetypeID(), oDLAttributes);

  oBlock.WritToDL(oDLBlock);
  return iStat;
}
//=============================================================================
int sstDxf03DatabaseCls::ReadMainTable( int iKey, dREC04RECNUMTYP dMainRecNo, RS2::EntityType *eEntityType, dREC04RECNUMTYP *dEntRecNo)
{
  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  sstDxf03TypMainCls oMainRec;

  iStat = this->oSstFncMain.Read( 0, dMainRecNo, &oMainRec);

  *eEntityType = oMainRec.getEntityType();

  *dEntRecNo = oMainRec.getTypeID();

  return iStat;
}
//=============================================================================
int sstDxf03DatabaseCls::updateAllMbr(int iKey)
{
  // int iRet  = 0;
  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;
  return iStat;
}
//=============================================================================
sstMath01Mbr2Cls sstDxf03DatabaseCls::getMbrModel()
{
  // Get mbr from block -modelspace-
  return this->oSstFncBlk.getMbrModel();
}
//=============================================================================
sstMath01Mbr2Cls sstDxf03DatabaseCls::getMbrBlock(dREC04RECNUMTYP dBlkNo)
{
  sstDxf03TypBlkCls oBlock;

  int iStat = this->oSstFncBlk.Read(0,dBlkNo,&oBlock);
  assert(iStat >= 0);

  return oBlock.getMbr();
}
//=============================================================================
int sstDxf03DatabaseCls::UpdateAttribWithId (int iKey,
                                          dREC04RECNUMTYP dLayID,
                                          dREC04RECNUMTYP dLTypeID,
                                          DL_Attributes *oDLAttributes)
//-----------------------------------------------------------------------------
{
  sstDxf03FncLayCls *oLocSstFncLay = NULL;       /**< layer sst table object */
  oLocSstFncLay = this->getSstFncLay();
  sstDxf03FncLTypeCls *oLocSstFncLType = NULL;   /**< linetype sst table object */
  oLocSstFncLType = this->getSstFncLType();

  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  if (dLayID > 0)
  {
    sstDxf03TypLayCls oLayRec;
    iStat = oLocSstFncLay->Read(0,dLayID,&oLayRec);
    oDLAttributes->setLayer(oLayRec.getName());
  }

  if (dLTypeID > 0)
  {
    sstDxf03TypLTypeCls oLTypeRec;
    iStat = oLocSstFncLType->Read(0,dLTypeID,&oLTypeRec);
    oDLAttributes->setLinetype( oLTypeRec.getName());
  }

  // Fatal Errors goes to an assert
  if (iRet < 0)
  {
    // Expression (iRet >= 0) has to be fullfilled
    assert(0);
  }

  // Small Errors will given back
  iRet = iStat;

  return iRet;
}
//=============================================================================
dREC04RECNUMTYP sstDxf03DatabaseCls::countBlocks()
{

  sstDxf03FncBlkCls *oBlkTab =  this->getSstFncBlk();
  return oBlkTab->count();
}
//=============================================================================
dREC04RECNUMTYP sstDxf03DatabaseCls::countEntities(int iKey, dREC04RECNUMTYP dBlkNo)
{
  if ( iKey != 0) return 0;

  if(dBlkNo == 0)
  { // Modelspace
    dREC04RECNUMTYP dMainTabRecNo1 = this->getMainTabSectEntStart();
    dREC04RECNUMTYP dMainTabRecNo2 = this->MainCount();
    return (dMainTabRecNo2-dMainTabRecNo1+1);
    // iStat = this->ReadMainTable(0,dActMainTabRecNo, eEntType, dEntNo);
    // assert(iStat >= 0);
    // return iStat;
  }


  sstDxf03FncBlkCls *oBlkTab =  this->getSstFncBlk();
  sstDxf03TypBlkCls oBlkRec;

  dREC04RECNUMTYP dNumBlks = oBlkTab->count();
  if (dBlkNo < 1 || dBlkNo > dNumBlks) return 0;

  int iStat = 0;
  dREC04RECNUMTYP dBlk_1 = 0;
  dREC04RECNUMTYP dBlk_2 = 0;
  iStat = oBlkTab->Read( 0, dBlkNo, &oBlkRec);
  assert(iStat >= 0);
  dBlk_1 = oBlkRec.getRecordID();
  if (dBlk_1 <= 0) return 0;

  if (dBlkNo < dNumBlks)
  {
    iStat = oBlkTab->Read( 0, dBlkNo+1, &oBlkRec);
    assert(iStat >= 0);
    dBlk_2 = oBlkRec.getRecordID();
  }
  else
  {  // last block
    dBlk_2 = this->getMainTabSectEntStart();
  }

  return dBlk_2-dBlk_1;
}
//=============================================================================
int sstDxf03DatabaseCls::ReadEntityType(int iKey,
                                        dREC04RECNUMTYP dBlkNo,
                                        dREC04RECNUMTYP dMainNo,
                                        RS2::EntityType *eEntType,
                                        dREC04RECNUMTYP *dEntNo)
{
  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  sstDxf03FncBlkCls *oBlkTab =  this->getSstFncBlk();
  sstDxf03TypBlkCls oBlkRec;

  dREC04RECNUMTYP dActMainTabRecNo = 0;

  if(dBlkNo == 0)
  { // Modelspace
    dActMainTabRecNo = this->getMainTabSectEntStart();
    iStat = this->ReadMainTable(0,dActMainTabRecNo+dMainNo-1, eEntType, dEntNo);
    assert(iStat >= 0);
    return iStat;
  }

  iStat = oBlkTab->Read( 0, dBlkNo, &oBlkRec);
  assert(iStat >= 0);

  // Calculate begin of block in maintable and read
  dActMainTabRecNo = oBlkRec.getRecordID()+dMainNo -1;
  iStat = this->ReadMainTable(0,dActMainTabRecNo, eEntType, dEntNo);
  assert(iStat >= 0);

  return iStat;
}
//=============================================================================
int sstDxf03DatabaseCls::GenerateData ( int iKey)
//-----------------------------------------------------------------------------
{
  int iRet = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  sstMath01dPnt2Cls oPnt;
  // oPnt.Set(0.0,0.0);
  // oPnt.Set(10.0,10.0);
  // oPnt.Set(100.0,100.0);
  // oPnt.Set(1000.0,1000.0);
  // oPnt.Set(10000.0,10000.0);
  // oPnt.Set(100000.0,100000.0);
  // oPnt.Set(1000000.0,1000000.0);
  // oPnt.Set(10000000.0,10000000.0);
  // oPnt.Set(30000000.0,5000000.0);  // not visible in librecad 2.1.2
  oPnt.Set(32540679.0,5804153.0);  // Utm Germany Lower Saxony

  // write new circle (border)
  DL_CircleData oDLCircle(oPnt.getX(),oPnt.getY(),0,1);
  DL_Attributes oAttributes;
  dREC04RECNUMTYP oEntRecNo = 0;
  dREC04RECNUMTYP oMainRecNo = 0;
  oAttributes.setLayer("0");
  oAttributes.setLinetype("CONTINUOUS");


  // Write new DL Circle object to sst dxf database
  iStat = this->WriteNewCircle( 0, oDLCircle, oAttributes, &oEntRecNo, &oMainRecNo);
  assert(iStat >= 0);

  //=== Insert filled circle area
  {
    oAttributes.setColor(1);

    DL_HatchData oDLHatch(1,1,1,0,"SOLID");
    DL_HatchEdgeData oDLHatchEdge(oPnt.getX()+3,oPnt.getY()+3,1,0,2*M_PI,1);  // Circle

    // open new dxflib hatch object in sstDxfDb
    iStat = this->OpenNewHatch( 0, oDLHatch, oAttributes, &oEntRecNo, &oMainRecNo);

    // write new dxflib hatch edge into sstDxfDb hatch object
    iStat = this->WriteNewHatchEdge ( 0, oDLHatchEdge, &oEntRecNo, &oMainRecNo);
  }

  //=== Insert filled triangel area
  {
    oAttributes.setColor(2);

    DL_HatchData oDLHatch(1,1,1,0,"SOLID");
    // open new dxflib hatch object in sstDxfDb
    iStat = this->OpenNewHatch( 0, oDLHatch, oAttributes, &oEntRecNo, &oMainRecNo);

    DL_HatchEdgeData oDLHatchEdge(oPnt.getX()+1,oPnt.getY()+1,
                                  oPnt.getX()+2,oPnt.getY()+2);  // area border point
    // write new dxflib hatch edge into sstDxfDb hatch object
    iStat = this->WriteNewHatchEdge ( 0, oDLHatchEdge, &oEntRecNo, &oMainRecNo);

    // write new dxflib hatch edge into sstDxfDb hatch object
    oDLHatchEdge.x1 = oPnt.getX() +2.0; oDLHatchEdge.y1 = oPnt.getY()+2.0;
    oDLHatchEdge.x2 = oPnt.getX() +1.0; oDLHatchEdge.y2 = oPnt.getY()+2.0;
    iStat = this->WriteNewHatchEdge ( 0, oDLHatchEdge, &oEntRecNo, &oMainRecNo);

    // write new dxflib hatch edge into sstDxfDb hatch object
    oDLHatchEdge.x1 = oPnt.getX() + 1.0; oDLHatchEdge.y1 = oPnt.getY()+2.0;
    oDLHatchEdge.x2 = oPnt.getX() + 1.0; oDLHatchEdge.y2 = oPnt.getY()+1.0;
    iStat = this->WriteNewHatchEdge ( 0, oDLHatchEdge, &oEntRecNo, &oMainRecNo);
  }
  {
    // Insert two Lines
    oEntRecNo = 0;
    DL_LineData oDlLine(oPnt.getX(),oPnt.getY()+1.5,0,oPnt.getX()+3,oPnt.getY()+4,0);
    iStat = this->WriteLine(0,oDlLine,oAttributes,&oEntRecNo,&oMainRecNo);
    oDlLine.x1 = oPnt.getX()+1; oDlLine.y1 = oPnt.getY() +2;
    oDlLine.x2 = oPnt.getX()+3.5; oDlLine.y2 = oPnt.getY() +4;
    oEntRecNo = 0;
    iStat = this->WriteLine(0,oDlLine,oAttributes,&oEntRecNo,&oMainRecNo);
  }

  // Fatal Errors goes to an assert
  assert(iRet >= 0);

  // Small Errors will given back
  iRet = iStat;

  return iRet;
}
//=============================================================================
