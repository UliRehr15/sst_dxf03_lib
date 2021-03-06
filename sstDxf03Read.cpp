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
// sstDxf03Read.cpp   05.07.19  Re.   26.02.16  Re.

#include <iostream>
#include <stdio.h>
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

//=============================================================================
sstDxf03ReadCls::sstDxf03ReadCls(sstDxf03DatabaseCls *oDxfDb, sstMisc01PrtFilCls *oTmpPrt)
{
  this->poPrt = oTmpPrt;
  this->poDxfDb = oDxfDb;
}
//=============================================================================
sstDxf03ReadCls::~sstDxf03ReadCls()
{
//  // update block table from information in main table
  this->poDxfDb->updateDb(0);

}
//=============================================================================
//void sstDxf03ReadCls::processCodeValuePair(unsigned int uiRow,const std::string &oRow)
//{
//  unsigned int uiTmpVal = uiRow;
//  int iStat = 0;
//}
////=============================================================================
void sstDxf03ReadCls::addLayer(const DL_LayerData& data)
{
  sstDxf03TypLayCls LayDs;
  sstDxf03FncLayCls *poLayFnc;
  poLayFnc = this->poDxfDb->getSstFncLay();

  sstDxf03TypLTypeCls oLTypeRec;
  sstDxf03FncLTypeCls *poLTypeTab;
  poLTypeTab = this->poDxfDb->getSstFncLType();

  dREC04RECNUMTYP dRecNo = 0;
    int LayNamLen = 0;
    int iStat = 0;
  //-----------------------------------------------------------------------------

    // Weiteren User-Datensatz in Datenspeicher schreiben.
    LayNamLen = strlen(data.name.c_str());
    if (LayNamLen < dSSTDXF03LAYERNAMELEN)
    {
      LayDs.setName(data.name.c_str());
      LayDs.setFlags( data.flags);
      LayDs.BaseReadFromDL(attributes);

      // write new Linetype record into table if not exist
      dREC04RECNUMTYP dLTypeRecNo = 0;
      oLTypeRec.setName(attributes.getLinetype());
      iStat = poLTypeTab->WriteNewUnique( 0, oLTypeRec, &dLTypeRecNo);

      LayDs.setLinetypeID(dLTypeRecNo);

      // Write new record into record memory and update all trees
      // iStat = poLayFnc->TreWriteNew( 0, &LayDs, &dRecNo);

      // Update existing layer or write new into table
      iStat = poLayFnc->UpdateWriteNew ( 0, LayDs, &dRecNo);
      assert(iStat >= 0);
    }
    else
    {
      assert(0);
    }
}
//=============================================================================
void sstDxf03ReadCls::addBlock(const DL_BlockData& data)
{
  int iStat = 0;

  iStat = this->poDxfDb->openBlock(0,data,attributes);
  assert(iStat >= 0);
//  sstDxf03TypBlkCls oBlk;
//  dREC04RECNUMTYP dRecNo = 0;
//  sstDxf03FncBlkCls *poBlkFnc;
//  poBlkFnc = this->poDxfDb->getSstFncBlk();

//  sstDxf03TypLTypeCls oLTypeRec;
//  sstDxf03FncLTypeCls *poLTypeTab;
//  poLTypeTab = this->poDxfDb->getSstFncLType();

//  oBlk.setName( data.name.c_str());
//  oBlk.BaseReadFromDL(attributes);

//  // write new Linetype record into table if not exist
//  dREC04RECNUMTYP dLTypeRecNo = 0;
//  oLTypeRec.setName(attributes.getLinetype());
//  iStat = poLTypeTab->WriteNewUnique( 0, oLTypeRec, &dLTypeRecNo);

  oActBlockNam = data.name;

//  // Write new record into record memory and update all trees
//  oBlk.setLinetypeID(dLTypeRecNo);
//  iStat = poBlkFnc->TreWriteNew( 0, &oBlk, &dRecNo);
//  assert(iStat == 0);
//  std::string oModelSpaceName = "*Model_Space";
//  iStat = oModelSpaceName.compare(data.name);
//  if(iStat == 0) poBlkFnc->setBlockMdlRecNo(dRecNo);
//  oModelSpaceName = "*MODEL_SPACE";
//  iStat = oModelSpaceName.compare(data.name);
//  if(iStat == 0) poBlkFnc->setBlockMdlRecNo(dRecNo);
}
//=============================================================================
void sstDxf03ReadCls::endBlock()
{
  this->poDxfDb->closeBlock(0);
  oActBlockNam.clear();
}
//=============================================================================
void sstDxf03ReadCls::addPoint(const DL_PointData& data)
{
//  printf("POINT    (%6.3f, %6.3f, %6.3f)\n",
//         data.x, data.y, data.z);
//  printAttributes();
//  this->poPrt->SST_PrtWrtChar( 1,(char*)"POINT skiped",(char*)"Dxf Reading: ");
  int iStat = 0;
  std::string oLayerStr;

  sstDxf03TypPointCls oDxfPoint;
  oDxfPoint.ReadFromDL(data);
  oDxfPoint.BaseReadFromDL(attributes);
  dREC04RECNUMTYP dRecNo=0;
  dREC04RECNUMTYP dLayRecNo=0;

  sstDxf03FncPointCls *poPointFnc;
  poPointFnc = this->poDxfDb->getSstFncPoint();
  sstDxf03FncLayCls *poLayFnc;
  poLayFnc = this->poDxfDb->getSstFncLay();
  sstDxf03FncBlkCls *poBlkFnc;
  poBlkFnc = this->poDxfDb->getSstFncBlk();
  sstDxf03FncMainCls *poMainFnc;
  poMainFnc = this->poDxfDb->getSstFncMain();

  dREC04RECNUMTYP dNumBlocks = 0;

  // is it layer or block??
  if (this->oActBlockNam.length() > 0)
  {  // Block
    dNumBlocks = poBlkFnc->count();
    oDxfPoint.setBlockID(dNumBlocks);
    // Set Minimum Bounding Rectangle in Block Table
    poBlkFnc->updateMbrBlock( 0, dNumBlocks, oDxfPoint.getMbr());

  }
  else
  {  // Layer
    oLayerStr = attributes.getLayer();
    // Find record with exact search value
    iStat = poLayFnc->TreSeaEQ( 0, poLayFnc->getNameSortKey(), (void*) oLayerStr.c_str(), &dLayRecNo);
    assert(iStat == 1);
    oDxfPoint.setLayerID(dLayRecNo);
    // Set Minimum Bounding Rectangle in Block Table
    poBlkFnc->updateMbrModel(0,oDxfPoint.getMbr());
  }
  iStat = poPointFnc->WritNew(0,&oDxfPoint,&dRecNo);

  sstDxf03TypMainCls oMainRec;

  dREC04RECNUMTYP dMainRecNo = poMainFnc->count();

  oMainRec.setMainID(dMainRecNo+1);
  oMainRec.setEntityType(RS2::EntityPoint);
  oMainRec.setTypeID(dRecNo);

  // Set Minimum Bounding Rectangle in Main Table
  oMainRec.setMbr(oDxfPoint.getMbr());

  // is it layer or block??
  if (this->oActBlockNam.length() > 0)
  {  // Block
    oMainRec.setLayBlockID(dNumBlocks);
    oMainRec.setSectString("B");
  }
  else
  {  // Layer
    oMainRec.setLayBlockID(dLayRecNo);
    oMainRec.setSectString("L");
  }
  iStat = poMainFnc->WritNew(0,&oMainRec,&dRecNo);
}
//=============================================================================
void sstDxf03ReadCls::addInsert(const DL_InsertData& data)
{
  int iStat = 0;
  std::string oLayerStr;
  std::string oBlockStr;

  sstDxf03FncInsertCls *poInsertFnc;
  poInsertFnc = this->poDxfDb->getSstFncInsert();
  sstDxf03FncLayCls *poLayFnc;
  poLayFnc = this->poDxfDb->getSstFncLay();
  sstDxf03FncBlkCls *poBlkFnc;
  poBlkFnc = this->poDxfDb->getSstFncBlk();
  sstDxf03FncMainCls *poMainFnc;
  poMainFnc = this->poDxfDb->getSstFncMain();

  sstDxf03TypInsertCls oDxfInsert;
  oDxfInsert.ReadFromDL(data);
  oDxfInsert.BaseReadFromDL(attributes);
  dREC04RECNUMTYP dRecNo=0;
  dREC04RECNUMTYP dLayRecNo=0;
  dREC04RECNUMTYP dBlkRecNo=0;

  dREC04RECNUMTYP dNumBlocks = 0;

  // is it element in section entities or block??
  if (this->oActBlockNam.length() > 0)
  {  // Block
    dNumBlocks = poBlkFnc->count();
    oDxfInsert.setBlockID(dNumBlocks);
  }
  else
  {  // entities
    oLayerStr = attributes.getLayer();
    // Find record with exact search value
    iStat = poLayFnc->TreSeaEQ( 0, poLayFnc->getNameSortKey(), (char*) oLayerStr.c_str(), &dLayRecNo);
    assert(iStat >= 0);
    if (iStat == 0)
    {
      // layer not found in layer table
      // write new layer data record with new name, take attributes from layer 0
      oLayerStr = "0";
      sstDxf03TypLayCls oLayRec;
      iStat = poLayFnc->TreSeaEQ( 0, poLayFnc->getNameSortKey(), (char*) oLayerStr.c_str(), &dLayRecNo);
      poLayFnc->Read(0,dLayRecNo,&oLayRec);
      oLayerStr = attributes.getLayer();
      oLayRec.setName(oLayerStr.c_str());
      // Write new record into record memory and update all trees
      iStat = poLayFnc->TreWriteNew( 0, &oLayRec, &dLayRecNo);

    }
    // Find block record with block name
    oBlockStr = data.name;
    iStat = poBlkFnc->TreSeaEQ( 0, poBlkFnc->getNameSortKey(), (void*) oBlockStr.c_str(), &dBlkRecNo);
    assert(iStat == 1);  // exit, if block not found in block table
    oDxfInsert.setBlockID(dBlkRecNo);

    // Handle Layer infos
    oDxfInsert.setLayerID(dLayRecNo);

    // Set Minimum Bounding Rectangle in Block Table
    // poBlkFnc->updateMbrModel(0,oDxfInsert.getMbr());
    sstMath01Mbr2Cls oBlkMbr = this->poDxfDb->getMbrBlock(dBlkRecNo);
    poBlkFnc->updateMbrModel(0,oDxfInsert.getMbr(oBlkMbr));

  }
  // write new insert record in insert table
  iStat = poInsertFnc->WritNew(0,&oDxfInsert,&dRecNo);
  assert(iStat == 0);

  sstDxf03TypMainCls oMainRec;

  dREC04RECNUMTYP dMainRecNo = poMainFnc->count();

  oMainRec.setMainID(dMainRecNo+1);
  oMainRec.setEntityType(RS2::EntityInsert);
  oMainRec.setTypeID(dRecNo);

  // is it layer or block??
  if (this->oActBlockNam.length() > 0)
  {  // Block
    oMainRec.setLayBlockID(dNumBlocks);
    oMainRec.setSectString("B");
  }
  else
  {  // Layer
   oMainRec.setLayBlockID(dLayRecNo);
    oMainRec.setSectString("L");
  }
  iStat = poMainFnc->WritNew(0,&oMainRec,&dRecNo);

}
//=============================================================================
void sstDxf03ReadCls::addLine(const DL_LineData& data) {

  int iStat = 0;
  std::string oLayerStr;

  sstDxf03TypLineCls oDxfLine;
  oDxfLine.ReadFromDL(data);
  oDxfLine.BaseReadFromDL(attributes);
  dREC04RECNUMTYP dRecNo=0;
  dREC04RECNUMTYP dLayRecNo=0;

  sstDxf03FncLineCls *poLineFnc;
  poLineFnc = this->poDxfDb->getSstFncLine();
  sstDxf03FncLayCls *poLayFnc;
  poLayFnc = this->poDxfDb->getSstFncLay();
  sstDxf03FncBlkCls *poBlkFnc;
  poBlkFnc = this->poDxfDb->getSstFncBlk();
  sstDxf03FncMainCls *poMainFnc;
  poMainFnc = this->poDxfDb->getSstFncMain();

  dREC04RECNUMTYP dNumBlocks = 0;

  // is it layer or block??
  if (this->oActBlockNam.length() > 0)
  {  // Block
    dNumBlocks = poBlkFnc->count();
    oDxfLine.setBlockID(dNumBlocks);
    // Set Minimum Bounding Rectangle in Block Table
    poBlkFnc->updateMbrBlock( 0, dNumBlocks, oDxfLine.getMbr());

  }
  else
  {  // Layer
    oLayerStr = attributes.getLayer();
    // Find record with exact search value
    iStat = poLayFnc->TreSeaEQ( 0, poLayFnc->getNameSortKey(), (void*) oLayerStr.c_str(), &dLayRecNo);
    assert(iStat == 1);
    oDxfLine.setLayerID(dLayRecNo);
    // Set Minimum Bounding Rectangle in Block Table
    poBlkFnc->updateMbrModel(0,oDxfLine.getMbr());
  }

  sstDxf03TypMainCls oMainRec;
  dREC04RECNUMTYP dMainRecNo = poMainFnc->count();

  oDxfLine.setMainRecNo(dMainRecNo+1);
  iStat = poLineFnc->WritNew(0,&oDxfLine,&dRecNo);

  oMainRec.setMainID(dMainRecNo+1);
  oMainRec.setEntityType(RS2::EntityLine);
  oMainRec.setTypeID(dRecNo);

  // Set Minimum Bounding Rectangle in Main Table
  oMainRec.setMbr(oDxfLine.getMbr());

  // is it layer or block??
  if (this->oActBlockNam.length() > 0)
  {  // Block
    oMainRec.setLayBlockID(dNumBlocks);
    oMainRec.setSectString("B");
  }
  else
  {  // Layer
    oMainRec.setLayBlockID(dLayRecNo);
    oMainRec.setSectString("L");
  }
  iStat = poMainFnc->WritNew(0,&oMainRec,&dMainRecNo);
  // iStat = poLineFnc->Writ( 0, &oDxfLine, dRecNo);
}
//=============================================================================
void sstDxf03ReadCls::addArc(const DL_ArcData& data)
{
  int iStat = 0;
  std::string oLayerStr;

  sstDxf03TypArcCls oDxfArc;
  oDxfArc.ReadFromDL(data);
  oDxfArc.BaseReadFromDL(attributes);
  dREC04RECNUMTYP dRecNo=0;
  dREC04RECNUMTYP dLayRecNo=0;

  sstDxf03FncArcCls *poArcFnc;
  poArcFnc = this->poDxfDb->getSstFncArc();
  sstDxf03FncLayCls *poLayFnc;
  poLayFnc = this->poDxfDb->getSstFncLay();
  sstDxf03FncBlkCls *poBlkFnc;
  poBlkFnc = this->poDxfDb->getSstFncBlk();
  sstDxf03FncMainCls *poMainFnc;
  poMainFnc = this->poDxfDb->getSstFncMain();

  dREC04RECNUMTYP dNumBlocks = 0;

  // is it layer or block??
  if (this->oActBlockNam.length() > 0)
  {  // Block
    dNumBlocks = poBlkFnc->count();
    oDxfArc.setBlockID(dNumBlocks);
    // Set Minimum Bounding Rectangle in Block Table
    poBlkFnc->updateMbrBlock( 0, dNumBlocks, oDxfArc.getMbr());
  }
  else
  {  // Layer
    oLayerStr = attributes.getLayer();
    // Find record with exact search value
    iStat = poLayFnc->TreSeaEQ( 0, poLayFnc->getNameSortKey(), (void*) oLayerStr.c_str(), &dLayRecNo);
    assert(iStat == 1);
    oDxfArc.setLayerID(dLayRecNo);
    // Set Minimum Bounding Rectangle in Block Table -model_space-
    poBlkFnc->updateMbrModel(0,oDxfArc.getMbr());
  }
  iStat = poArcFnc->WritNew(0,&oDxfArc,&dRecNo);

  sstDxf03TypMainCls oMainRec;

  dREC04RECNUMTYP dMainRecNo = poMainFnc->count();

  oMainRec.setMainID(dMainRecNo+1);
  oMainRec.setEntityType(RS2::EntityArc);
  oMainRec.setTypeID(dRecNo);

  // is it layer or block??
  if (this->oActBlockNam.length() > 0)
  {  // Block
    oMainRec.setLayBlockID(dNumBlocks);
    oMainRec.setSectString("B");
  }
  else
  {  // Layer
    oMainRec.setLayBlockID(dLayRecNo);
    oMainRec.setSectString("L");
  }
  iStat = poMainFnc->WritNew(0,&oMainRec,&dRecNo);
}
//=============================================================================
void sstDxf03ReadCls::addCircle(const DL_CircleData& data)
{
  int iStat = 0;
  std::string oLayerStr;

  sstDxf03TypCircleCls oDxfCircle;
  oDxfCircle.ReadFromDL(data);
  oDxfCircle.BaseReadFromDL(attributes);
  dREC04RECNUMTYP dRecNo=0;
  dREC04RECNUMTYP dLayRecNo=0;

  sstDxf03FncCircleCls *poCircleFnc;
  poCircleFnc = this->poDxfDb->getSstFncCircle();
  sstDxf03FncLayCls *poLayFnc;
  poLayFnc = this->poDxfDb->getSstFncLay();
  sstDxf03FncBlkCls *poBlkFnc;
  poBlkFnc = this->poDxfDb->getSstFncBlk();
  sstDxf03FncMainCls *poMainFnc;
  poMainFnc = this->poDxfDb->getSstFncMain();

  dREC04RECNUMTYP dNumBlocks = 0;

  // is it layer or block??
  if (this->oActBlockNam.length() > 0)
  {  // Block
    dNumBlocks = poBlkFnc->count();
    oDxfCircle.setBlockID(dNumBlocks);
    // Set Minimum Bounding Rectangle in Block Table
    poBlkFnc->updateMbrBlock( 0, dNumBlocks, oDxfCircle.getMbr());

  }
  else
  {  // Layer
    oLayerStr = attributes.getLayer();
    // Find record with exact search value
    iStat = poLayFnc->TreSeaEQ( 0, poLayFnc->getNameSortKey(), (void*) oLayerStr.c_str(), &dLayRecNo);
    assert(iStat == 1);
    oDxfCircle.setLayerID(dLayRecNo);
    // Set Minimum Bounding Rectangle in Block Table -model_space-
    poBlkFnc->updateMbrModel(0,oDxfCircle.getMbr());
  }

  sstDxf03TypMainCls oMainRec;
  dREC04RECNUMTYP dMainRecNo = poMainFnc->count();

  oDxfCircle.setMainRecNo(dMainRecNo+1);
  iStat = poCircleFnc->WritNew(0,&oDxfCircle,&dRecNo);

  oMainRec.setMainID(dMainRecNo+1);
  oMainRec.setEntityType(RS2::EntityCircle);
  oMainRec.setTypeID(dRecNo);

  // is it layer or block??
  if (this->oActBlockNam.length() > 0)
  {  // Block
    oMainRec.setLayBlockID(dNumBlocks);
    oMainRec.setSectString("B");
  }
  else
  {  // Layer
    oMainRec.setLayBlockID(dLayRecNo);
    oMainRec.setSectString("L");
  }
  iStat = poMainFnc->WritNew(0,&oMainRec,&dRecNo);
}
//=============================================================================
void sstDxf03ReadCls::addMText(const DL_MTextData& data) {
//    printf("MText \n");
//    printAttributes();
  //  this->poPrt->SST_PrtWrtChar( 1,(char*)"MTEXT skiped",(char*)"Dxf Reading: ");
  int iStat = 0;
  std::string oLayerStr;

  sstDxf03TypMTextCls oDxfMText;
  oDxfMText.ReadFromDL(data);
  oDxfMText.BaseReadFromDL(attributes);
  dREC04RECNUMTYP dRecNo=0;
  dREC04RECNUMTYP dLayRecNo=0;

  sstDxf03FncMTextCls *poMTextFnc;
  poMTextFnc = this->poDxfDb->getSstFncMText();
  sstDxf03FncLayCls *poLayFnc;
  poLayFnc = this->poDxfDb->getSstFncLay();
  sstDxf03FncBlkCls *poBlkFnc;
  poBlkFnc = this->poDxfDb->getSstFncBlk();
  sstDxf03FncMainCls *poMainFnc;
  poMainFnc = this->poDxfDb->getSstFncMain();

  dREC04RECNUMTYP dNumBlocks = 0;

  // is it layer or block??
  if (this->oActBlockNam.length() > 0)
  {  // Block
    dNumBlocks = poBlkFnc->count();
    oDxfMText.setBlockID(dNumBlocks);
  }
  else
  {  // Layer
    oLayerStr = attributes.getLayer();
    // Find record with exact search value
    iStat = poLayFnc->TreSeaEQ( 0, poLayFnc->getNameSortKey(), (void*) oLayerStr.c_str(), &dLayRecNo);
    assert(iStat == 1);
    oDxfMText.setLayerID(dLayRecNo);
  }
  iStat = poMTextFnc->WritNew(0,&oDxfMText,&dRecNo);

  sstDxf03TypMainCls oMainRec;

  dREC04RECNUMTYP dMainRecNo = poMainFnc->count();

  oMainRec.setMainID(dMainRecNo+1);
  oMainRec.setEntityType(RS2::EntityMText);
  oMainRec.setTypeID(dRecNo);

  // is it layer or block??
  if (this->oActBlockNam.length() > 0)
  {  // Block
    oMainRec.setLayBlockID(dNumBlocks);
    oMainRec.setSectString("B");
  }
  else
  {  // Layer
    oMainRec.setLayBlockID(dLayRecNo);
    oMainRec.setSectString("L");
  }
  iStat = poMainFnc->WritNew(0,&oMainRec,&dRecNo);
}
//=============================================================================
void sstDxf03ReadCls::addText(const DL_TextData& data)
{
  int iStat = 0;
  std::string oLayerStr;

  sstDxf03TypTextCls oDxfText;
  oDxfText.ReadFromDL(data);
  oDxfText.BaseReadFromDL(attributes);
  dREC04RECNUMTYP dRecNo=0;
  dREC04RECNUMTYP dLayRecNo=0;

  sstDxf03FncTextCls *poTextFnc;
  poTextFnc = this->poDxfDb->getSstFncText();
  sstDxf03FncLayCls *poLayFnc;
  poLayFnc = this->poDxfDb->getSstFncLay();
  sstDxf03FncBlkCls *poBlkFnc;
  poBlkFnc = this->poDxfDb->getSstFncBlk();
  sstDxf03FncMainCls *poMainFnc;
  poMainFnc = this->poDxfDb->getSstFncMain();

  dREC04RECNUMTYP dNumBlocks = 0;

  // is it layer or block??
  if (this->oActBlockNam.length() > 0)
  {  // Block
    dNumBlocks = poBlkFnc->count();
    oDxfText.setBlockID(dNumBlocks);
  }
  else
  {  // Layer
    oLayerStr = attributes.getLayer();
    // Find record with exact search value
    iStat = poLayFnc->TreSeaEQ( 0, poLayFnc->getNameSortKey(), (void*) oLayerStr.c_str(), &dLayRecNo);
    if (iStat < 0)
    {
      assert(iStat == 1);
    }
    oDxfText.setLayerID(dLayRecNo);
  }
  iStat = poTextFnc->WritNew(0,&oDxfText,&dRecNo);

  sstDxf03TypMainCls oMainRec;

  dREC04RECNUMTYP dMainRecNo = poMainFnc->count();

  oMainRec.setMainID(dMainRecNo+1);
  oMainRec.setEntityType(RS2::EntityText);
  oMainRec.setTypeID(dRecNo);

  // is it layer or block??
  if (this->oActBlockNam.length() > 0)
  {  // Block
    oMainRec.setLayBlockID(dNumBlocks);
    oMainRec.setSectString("B");
  }
  else
  {  // Layer
    oMainRec.setLayBlockID(dLayRecNo);
    oMainRec.setSectString("L");
  }
  iStat = poMainFnc->WritNew(0,&oMainRec,&dRecNo);
//     this->poPrt->SST_PrtWrtChar( 1,(char*)"CIRCLE skiped",(char*)"Dxf Reading: ");
}

//}
//=============================================================================
void sstDxf03ReadCls::addPolyline(const DL_PolylineData& data)
{
  int iStat = 0;

  sstDxf03TypPolylineCls oDxfPolyline;
  oDxfPolyline.ReadFromDL(data);
  oDxfPolyline.BaseReadFromDL(attributes);
  dREC04RECNUMTYP dEntRecNo=0;
  dREC04RECNUMTYP dLayRecNo=0;
  dREC04RECNUMTYP dLTypeRecNo=0;

  sstDxf03FncPolylineCls *poPolylineFnc;
  poPolylineFnc = this->poDxfDb->getSstFncPolyline();

  sstDxf03FncLayCls *poLayFnc;
  poLayFnc = this->poDxfDb->getSstFncLay();

  sstDxf03FncLTypeCls *poLTypeFnc;
  poLTypeFnc = this->poDxfDb->getSstFncLType();

  sstDxf03FncBlkCls *poBlkFnc;
  poBlkFnc = this->poDxfDb->getSstFncBlk();

  sstDxf03FncMainCls *poMainFnc;
  poMainFnc = this->poDxfDb->getSstFncMain();

  dREC04RECNUMTYP dNumBlocks = 0;

  // is it layer or block??
  if (this->oActBlockNam.length() > 0)
  {  // Block
    dNumBlocks = poBlkFnc->count();
    oDxfPolyline.setBlockID(dNumBlocks);
  }
  else
  {  // Layer
    std::string oLayerStr;
    oLayerStr = attributes.getLayer();
    // Find record with exact search value
    iStat = poLayFnc->TreSeaEQ( 0, poLayFnc->getNameSortKey(), (void*) oLayerStr.c_str(), &dLayRecNo);
    assert(iStat == 1);
    oDxfPolyline.setLayerID(dLayRecNo);


  }
  std::string oLTypeStr;
  oLTypeStr = attributes.getLinetype();

  std::transform(oLTypeStr.begin(), oLTypeStr.end(),oLTypeStr.begin(), ::toupper);

  // Find record with exact search value
  iStat = poLTypeFnc->TreSeaEQ( 0, poLTypeFnc->getNameSortKey(), (void*) oLTypeStr.c_str(), &dLTypeRecNo);
  assert(iStat == 1);
  oDxfPolyline.setLinetypeID(dLTypeRecNo);

  dREC04RECNUMTYP dMainRecNo = poMainFnc->count();
  oDxfPolyline.setMainRecNo(dMainRecNo+1);
  iStat = poPolylineFnc->WritNew(0,&oDxfPolyline,&dEntRecNo);

  sstDxf03TypMainCls oMainRec;

  oMainRec.setMainID(dMainRecNo+1);
  oMainRec.setEntityType(RS2::EntityPolyline);
  oMainRec.setTypeID(dEntRecNo);

  // is it layer or block??
  if (this->oActBlockNam.length() > 0)
  {  // Block
    oMainRec.setLayBlockID(dNumBlocks);
    oMainRec.setSectString("B");
  }
  else
  {  // Layer
    oMainRec.setLayBlockID(dLayRecNo);
    oMainRec.setSectString("L");
  }
  iStat = poMainFnc->WritNew(0,&oMainRec,&dMainRecNo);

  this->poDxfDb->setGrpMainID( dEntRecNo);
  this->poDxfDb->setActEntType(RS2::EntityPolyline);

}
//=============================================================================
void sstDxf03ReadCls::addVertex(const DL_VertexData& data)
{
  // int iStat = 0;
  // std::string oLayerStr;

  sstDxf03TypVertexCls oDxfVertex;
  oDxfVertex.ReadFromDL(data);
  // oDxfVertex.BaseReadFromDL(attributes);
  dREC04RECNUMTYP dRecNo=0;
  dREC04RECNUMTYP dLayRecNo=0;

  sstDxf03FncVertexCls *poVertexFnc;
  poVertexFnc = this->poDxfDb->getSstFncVertex();
  sstDxf03FncMainCls *poMainFnc;
  poMainFnc = this->poDxfDb->getSstFncMain();
  sstDxf03FncBlkCls *poBlkFnc;
  poBlkFnc = this->poDxfDb->getSstFncBlk();

  dREC04RECNUMTYP dNumBlocks = 0;

  sstMath01Mbr2Cls oTmpMbr;
  oTmpMbr.IniPkt2(0,oDxfVertex.getX(),oDxfVertex.getY());

  // is it layer or block??
  if (this->oActBlockNam.length() > 0)
  {  // Block
    dNumBlocks = poBlkFnc->count();
    // Set Minimum Bounding Rectangle in Block Table
    poBlkFnc->updateMbrBlock( 0, dNumBlocks, oTmpMbr);
  }
  else
  {
    // Set Minimum Bounding Rectangle in Block Table
    poBlkFnc->updateMbrModel( 0, oTmpMbr);
  }

  oDxfVertex.setParentID(this->poDxfDb->getGrpMainID());
  oDxfVertex.setEntityType(this->poDxfDb->getActEntType());

  poVertexFnc->WritNew(0,&oDxfVertex,&dRecNo);

  sstDxf03TypMainCls oMainRec;

  dREC04RECNUMTYP dMainRecNo = poMainFnc->count();

  oMainRec.setMainID(dMainRecNo+1);
  oMainRec.setEntityType(RS2::EntityVertex);
  oMainRec.setTypeID(dRecNo);

  // is it layer or block??
  if (this->oActBlockNam.length() > 0)
  {  // Block
    oMainRec.setLayBlockID(dNumBlocks);
    oMainRec.setSectString("B");
  }
  else
  {  // Layer
    oMainRec.setLayBlockID(dLayRecNo);
    oMainRec.setSectString("L");
  }
  poMainFnc->WritNew(0,&oMainRec,&dRecNo);
}
//=============================================================================
void sstDxf03ReadCls::add3dFace(const DL_3dFaceData& data) {
  int iStat = 0;
  std::string oLayerStr;

  sstDxf03TypTraceCls oDxfTrace;
  oDxfTrace.ReadFromDL(data);
  oDxfTrace.BaseReadFromDL(attributes);
  dREC04RECNUMTYP dRecNo=0;
  dREC04RECNUMTYP dLayRecNo=0;

  sstDxf03FncTraceCls *poTraceFnc;
  poTraceFnc = this->poDxfDb->getSstFncTrace();
  sstDxf03FncLayCls *poLayFnc;
  poLayFnc = this->poDxfDb->getSstFncLay();
  sstDxf03FncBlkCls *poBlkFnc;
  poBlkFnc = this->poDxfDb->getSstFncBlk();
  sstDxf03FncMainCls *poMainFnc;
  poMainFnc = this->poDxfDb->getSstFncMain();

  dREC04RECNUMTYP dNumBlocks = 0;

  // is it layer or block??
  if (this->oActBlockNam.length() > 0)
  {  // Block
    dNumBlocks = poBlkFnc->count();
    oDxfTrace.setBlockID(dNumBlocks);
  }
  else
  {  // Layer
    oLayerStr = attributes.getLayer();
    // Find record with exact search value
    iStat = poLayFnc->TreSeaEQ( 0, poLayFnc->getNameSortKey(), (void*) oLayerStr.c_str(), &dLayRecNo);
    assert(iStat == 1);
    oDxfTrace.setLayerID(dLayRecNo);
  }
  iStat = poTraceFnc->WritNew(0,&oDxfTrace,&dRecNo);

  sstDxf03TypMainCls oMainRec;

  dREC04RECNUMTYP dMainRecNo = poMainFnc->count();

  oMainRec.setMainID(dMainRecNo+1);
  oMainRec.setEntityType(RS2::EntityUnknown);  // no EntityTrace
  oMainRec.setTypeID(dRecNo);

  // is it layer or block??
  if (this->oActBlockNam.length() > 0)
  {  // Block
    oMainRec.setLayBlockID(dNumBlocks);
    oMainRec.setSectString("B");
  }
  else
  {  // Layer
    oMainRec.setLayBlockID(dLayRecNo);
    oMainRec.setSectString("L");
  }
  iStat = poMainFnc->WritNew(0,&oMainRec,&dRecNo);
//    printf("3DFACE\n");
//    for (int i=0; i<4; i++) {
//        printf("   corner %d: %6.3f %6.3f %6.3f\n",
//            i, data.x[i], data.y[i], data.z[i]);
//    }
//    printAttributes();
//    this->poPrt->SST_PrtWrtChar( 1,(char*)"FACE skiped",(char*)"Dxf Reading: ");
}
//=============================================================================
void sstDxf03ReadCls::addHatch(const DL_HatchData& data)
{
  int iStat = 0;
  std::string oLayerStr;

  sstDxf03TypHatchCls oDxfHatch;
  oDxfHatch.ReadFromDL(data);
  oDxfHatch.BaseReadFromDL(attributes);
  dREC04RECNUMTYP dEntRecNo=0;
  dREC04RECNUMTYP dLayRecNo=0;
  dREC04RECNUMTYP dLTypeRecNo=0;

  sstDxf03FncHatchCls *poHatchFnc;
  poHatchFnc = this->poDxfDb->getSstFncHatch();
  sstDxf03FncLayCls *poLayFnc;
  poLayFnc = this->poDxfDb->getSstFncLay();
  sstDxf03FncBlkCls *poBlkFnc;
  poBlkFnc = this->poDxfDb->getSstFncBlk();
  sstDxf03FncMainCls *poMainFnc;
  poMainFnc = this->poDxfDb->getSstFncMain();

  dREC04RECNUMTYP dNumBlocks = 0;

  // is it layer or block??
  if (this->oActBlockNam.length() > 0)
  {  // Block
    dNumBlocks = poBlkFnc->count();
    oDxfHatch.setBlockID(dNumBlocks);
  }
  else
  {  // Layer
    oLayerStr = attributes.getLayer();
    // Find record with exact search value
    iStat = poLayFnc->TreSeaEQ( 0, poLayFnc->getNameSortKey(), (void*) oLayerStr.c_str(), &dLayRecNo);
    assert(iStat == 1);
    oDxfHatch.setLayerID(dLayRecNo);
  }

  sstDxf03FncLTypeCls *poLTypeFnc;
  poLTypeFnc = this->poDxfDb->getSstFncLType();

  std::string oLTypeStr;
  oLTypeStr = attributes.getLinetype();

  std::transform(oLTypeStr.begin(), oLTypeStr.end(),oLTypeStr.begin(), ::toupper);

  // Find record with exact search value
  iStat = poLTypeFnc->TreSeaEQ( 0, poLTypeFnc->getNameSortKey(), (void*) oLTypeStr.c_str(), &dLTypeRecNo);
  assert(iStat == 1);
  oDxfHatch.setLinetypeID(dLTypeRecNo);

  dREC04RECNUMTYP dMainRecNo = poMainFnc->count();
  oDxfHatch.setMainRecNo(dMainRecNo+1);
  iStat = poHatchFnc->WritNew(0,&oDxfHatch,&dEntRecNo);
  assert(iStat == 0);

  sstDxf03TypMainCls oMainRec;

  // dREC04RECNUMTYP dMainRecNo = poMainFnc->count();

  oMainRec.setMainID(dMainRecNo+1);
  oMainRec.setEntityType(RS2::EntityHatch);
  oMainRec.setTypeID(dEntRecNo);

  // is it layer or block??
  if (this->oActBlockNam.length() > 0)
  {  // Block
    oMainRec.setLayBlockID(dNumBlocks);
    oMainRec.setSectString("B");
  }
  else
  {  // Layer
    oMainRec.setLayBlockID(dLayRecNo);
    oMainRec.setSectString("L");
  }
  iStat = poMainFnc->WritNew(0,&oMainRec,&dMainRecNo);
  assert(iStat == 0);

  this->poDxfDb->setGrpMainID( dEntRecNo);

}
//=============================================================================
void sstDxf03ReadCls::addHatchEdge(const DL_HatchEdgeData& data)
{
  int iStat = 0;
  std::string oLayerStr;

  sstDxf03TypHatchEdgeCls oDxfHatchEdge;
  oDxfHatchEdge.ReadFromDL(data);
  // oDxfArc.BaseReadFromDL(attributes);
  dREC04RECNUMTYP dRecNo=0;
  dREC04RECNUMTYP dLayRecNo=0;

  sstDxf03FncHatchEdgeCls *poHatchEdgeFnc;
  poHatchEdgeFnc = this->poDxfDb->getSstFncHatchEdge();

  sstDxf03FncBlkCls *poBlkFnc;
  poBlkFnc = this->poDxfDb->getSstFncBlk();

  sstDxf03FncMainCls *poMainFnc;
  poMainFnc = this->poDxfDb->getSstFncMain();

  dREC04RECNUMTYP dNumBlocks = 0;

  oDxfHatchEdge.setParentID(this->poDxfDb->getGrpMainID());

  iStat = poHatchEdgeFnc->WritNew(0,&oDxfHatchEdge,&dRecNo);
  assert(iStat == 0);

  sstDxf03TypMainCls oMainRec;

  dREC04RECNUMTYP dMainRecNo = poMainFnc->count();

  oMainRec.setMainID(dMainRecNo+1);
  oMainRec.setEntityType(RS2::EntityHatchEdge);
  oMainRec.setTypeID(dRecNo);

  // is it layer or block??
  if (this->oActBlockNam.length() > 0)
  {  // Block
    dNumBlocks = poBlkFnc->count();
    oMainRec.setLayBlockID(dNumBlocks);
    oMainRec.setSectString("B");
    // Set Minimum Bounding Rectangle in Block Table
    poBlkFnc->updateMbrBlock( 0, dNumBlocks, oDxfHatchEdge.getMbr());

  }
  else
  {  // Layer
    // Set Minimum Bounding Rectangle in Block Table
    poBlkFnc->updateMbrModel( 0, oDxfHatchEdge.getMbr());

    oMainRec.setLayBlockID(dLayRecNo);
    oMainRec.setSectString("L");
  }
  iStat = poMainFnc->WritNew(0,&oMainRec,&dRecNo);
  assert(iStat == 0);

}
//=============================================================================
void sstDxf03ReadCls::addHatchLoop(const DL_HatchLoopData& data)
{
  int iStat = 0;
  std::string oLayerStr;

  sstDxf03TypHatchLoopCls oDxfHatchLoop;
  oDxfHatchLoop.ReadFromDL(data);
  dREC04RECNUMTYP dRecNo=0;
  dREC04RECNUMTYP dLayRecNo=0;

  sstDxf03FncHatchLoopCls *poHatchLoopFnc;
  poHatchLoopFnc = this->poDxfDb->getSstFncHatchLoop();
  sstDxf03FncMainCls *poMainFnc;
  poMainFnc = this->poDxfDb->getSstFncMain();
  sstDxf03FncBlkCls *poBlkFnc;
  poBlkFnc = this->poDxfDb->getSstFncBlk();

  dREC04RECNUMTYP dNumBlocks = 0;

  iStat = poHatchLoopFnc->WritNew(0,&oDxfHatchLoop,&dRecNo);
  assert (iStat == 0);

  sstDxf03TypMainCls oMainRec;

  dREC04RECNUMTYP dMainRecNo = poMainFnc->count();

  oMainRec.setMainID(dMainRecNo+1);
  oMainRec.setEntityType(RS2::EntityHatchLoop);
  oMainRec.setTypeID(dRecNo);

  // is it layer or block??
  if (this->oActBlockNam.length() > 0)
  {  // Block
    dNumBlocks = poBlkFnc->count();
    oMainRec.setLayBlockID(dNumBlocks);
    oMainRec.setSectString("B");
  }
  else
  {  // Layer
    oMainRec.setLayBlockID(dLayRecNo);
    oMainRec.setSectString("L");
  }
  iStat = poMainFnc->WritNew(0,&oMainRec,&dRecNo);
  assert (iStat == 0);

}
//=============================================================================
void sstDxf03ReadCls::addSolid(const DL_SolidData& data)
{
  int iStat = 0;
  std::string oLayerStr;

  sstDxf03TypTraceCls oDxfTrace;
  oDxfTrace.ReadFromDL(data);
  oDxfTrace.BaseReadFromDL(attributes);
  dREC04RECNUMTYP dRecNo=0;
  dREC04RECNUMTYP dLayRecNo=0;

  sstDxf03FncTraceCls *poTraceFnc;
  poTraceFnc = this->poDxfDb->getSstFncTrace();
  sstDxf03FncLayCls *poLayFnc;
  poLayFnc = this->poDxfDb->getSstFncLay();
  sstDxf03FncBlkCls *poBlkFnc;
  poBlkFnc = this->poDxfDb->getSstFncBlk();
  sstDxf03FncMainCls *poMainFnc;
  poMainFnc = this->poDxfDb->getSstFncMain();

  dREC04RECNUMTYP dNumBlocks = 0;

  // is it layer or block??
  if (this->oActBlockNam.length() > 0)
  {  // Block
    dNumBlocks = poBlkFnc->count();
    oDxfTrace.setBlockID(dNumBlocks);
  }
  else
  {  // Layer
    oLayerStr = attributes.getLayer();
    // Find record with exact search value
    iStat = poLayFnc->TreSeaEQ( 0, poLayFnc->getNameSortKey(), (void*) oLayerStr.c_str(), &dLayRecNo);
    assert(iStat == 1);
    oDxfTrace.setLayerID(dLayRecNo);
  }
  iStat = poTraceFnc->WritNew(0,&oDxfTrace,&dRecNo);

  sstDxf03TypMainCls oMainRec;

  dREC04RECNUMTYP dMainRecNo = poMainFnc->count();

  oMainRec.setMainID(dMainRecNo+1);
  oMainRec.setEntityType(RS2::EntityUnknown);  // no entity::trace
  oMainRec.setTypeID(dRecNo);

  // is it layer or block??
  if (this->oActBlockNam.length() > 0)
  {  // Block
    oMainRec.setLayBlockID(dNumBlocks);
    oMainRec.setSectString("B");
  }
  else
  {  // Layer
    oMainRec.setLayBlockID(dLayRecNo);
    oMainRec.setSectString("L");
  }
  iStat = poMainFnc->WritNew(0,&oMainRec,&dRecNo);

  // this->poPrt->SST_PrtWrtChar( 1,(char*)"SOLID skiped",(char*)"Dxf Reading: ");
  // int iStat = 0;
}
////=============================================================================
//void sstDxf03ReadCls::printAttributes() {
//    printf("  Attributes: Layer: %s, ", attributes.getLayer().c_str());
//    printf(" Color: ");
//    if (attributes.getColor()==256)	{
//        printf("BYLAYER");
//    } else if (attributes.getColor()==0) {
//        printf("BYBLOCK");
//    } else {
//        printf("%d", attributes.getColor());
//    }
//    printf(" Width: ");
//    if (attributes.getWidth()==-1) {
//        printf("BYLAYER");
//    } else if (attributes.getWidth()==-2) {
//        printf("BYBLOCK");
//    } else if (attributes.getWidth()==-3) {
//        printf("DEFAULT");
//    } else {
//        printf("%d", attributes.getWidth());
//    }
//    printf(" Type: %s\n", attributes.getLineType().c_str());
//}
//=============================================================================
void sstDxf03ReadCls::SetDxfFilNam(char* cTmpDxfFilNam)
{
  std::string oTmpStr;
  sstMisc01FilNamCls oFilNam;
  oTmpStr = cTmpDxfFilNam;
  // Remove extension from dxf file name and store in sst dxf read object
  oFilNam.RemoveExtension(0,"dxf",oTmpStr,&this->oDxfFilNam);
}
//=============================================================================

// EOF
