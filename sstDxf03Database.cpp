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
//  sstDxf03Database.cpp   01.11.16  Re.   06.07.16  Re.
//
//  Functions for Class "sstDxf03Lib"
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
  dActRecNo = 0;                               // Actual Record Number
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

  oDL_Attr.setLineType("CONTINUOUS");

  oLayRec.ReadFromDL(oDL_Lay);
  oLayRec.BaseReadFromDL(oDL_Attr);

  oLayRec.setLinetypeID(1);

  oLayTab = this->getSstFncLay();

  iStat = oLayTab->WritNew(0,&oLayRec,&dRecNo);
  assert(iStat == 0);

  // default write Blocks in database


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

  // Read whole hatch loop csv file into sst_rec_mem
  iStat = oSstFncCircle.ReadCsvFile ( 0, oFilNamCircle);

  // Read whole hatch loop csv file into sst_rec_mem
  iStat = oSstFncMText.ReadCsvFile ( 0, oFilNamMText);

  // Read whole hatch loop csv file into sst_rec_mem
  iStat = oSstFncText.ReadCsvFile ( 0, oFilNamText);

  // Read whole point csv file into sst_rec_mem
  iStat = oSstFncPoint.ReadCsvFile ( 0, oFilNamPoint);

  // Read whole line csv file into sst_rec_mem
  iStat = oSstFncLine.ReadCsvFile ( 0, oFilNamLine);

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
dREC04RECNUMTYP sstDxf03DatabaseCls::getActRecNo() const
{
return dActRecNo;
}
//=============================================================================
void sstDxf03DatabaseCls::setActRecNo(const dREC04RECNUMTYP &value)
{
dActRecNo = value;
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
  oLTypeStr = oDLAttributes.getLineType();

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

  this->setActRecNo(*oEntRecNo);
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

  oDxfHatchEdge.setParentID(this->getActRecNo());

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

  // std::cout << "Reading file " << file << "...\n";
  // std::cout << "Reading file " << oDxfFilNam << "...\n";
  this->oPrt->SST_PrtWrtChar(1,(char*) oDxfFilNam.c_str(), (char*)"Reading file: ");
  sstDxf03ReadCls* creationClass = new sstDxf03ReadCls( this, this->GetPrtAdr());

  creationClass->SetDxfFilNam((char*) oDxfFilNam.c_str());

  DL_Dxf* dxf = new DL_Dxf();
  if (!dxf->in(oDxfFilNam, creationClass))
  { // if file open failed
      // std::cerr << oDxfFilNam << " could not be opened.\n";
    this->oPrt->SST_PrtWrtChar(1,(char*) oDxfFilNam.c_str(),(char*)"Error: Could not open: ");
      iStat = -2;
      // return;
  }
  delete dxf;
  delete creationClass;

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
  case RS2::EntityHatch:
    dTmpCount = this->oSstFncHatch.count();
    break;
  case RS2::EntityHatchLoop:
    dTmpCount = this->oSstFncHatchLoop.count();
    break;
  case RS2::EntityHatchEdge:
    dTmpCount = this->oSstFncHatchEdge.count();
    break;
  default:
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
  oCircle.WritToDL(oDLCircle);
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
