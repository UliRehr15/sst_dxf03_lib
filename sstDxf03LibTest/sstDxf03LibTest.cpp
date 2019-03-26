/**********************************************************************
 *
 * sstDxf02LibTest - sst dxf library testing
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
// sstdxf03LibTest.cpp    16.05.18  Re.    13.07.16  Re.
//
// Testframe for sstDxf03Lib Function testing

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
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

#include "sstDxf03LibTest.h"

//=============================================================================
int main()
{
  int iStat = 0;
  unsigned long ulRowNo = 0;

  {
    DL_PointData oDLPoint;               // Entity Point from dxflib
    DL_PolylineData oDlPolyline(0,0,0,0);
    DL_VertexData oDlVertex(0.0,0.0,0.0,0.0);
    DL_LineData  oDLLine(0,0,0,0,0,0);   // Entity Line from dxflib
    DL_CircleData oDLCircle(0,0,0,1);    // Entity Circle from dxflib
    DL_MTextData oDLMText(0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0,0.0,"","",0.0);
    DL_TextData oDLText(0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0,"","",0.0);
    DL_InsertData("test",0,0,0,0,0,0,0,0,0,0,0);
    DL_HatchData oDlHatch(0,0,0.0,0.0,"pattern",0.0,0.0);
    DL_ArcData oDlArc(0.0,0.0,0.0,0.0,0.0,0.0);
  }

  sstMisc01PrtFilCls oPrt;
  iStat = oPrt.SST_PrtAuf(1,(char*)"sstDxf03LibTest.log");
  if(iStat < 0)
  {
    oPrt.SST_PrtWrt(1,(char*)"Error Opening Protocolfile");
    oPrt.SST_PrtZu(1);
    return 0;
    // assert(iStat >= 0);
  }
  {
    // Open new sstDxf Database
    sstDxf03DbCls oDxfDb( &oPrt);

    RS2::EntityType eEntityType = oDxfDb.CnvtTypeString2Enum("dddd");
    assert(eEntityType == RS2::EntityUnknown);

    // Return empty mbr, because modelspace empty.
    sstMath01Mbr2Cls oMbr = oDxfDb.getMbrModel();

    // Generate dxf data in utm area (Germany)  <BR>
    iStat = oDxfDb.GenerateData( 0);
    assert(iStat >= 0);

    // Look for first record in entity line table and get rec no in main table
    eEntityType = RS2::EntityLine;
    dREC04RECNUMTYP dEntRecNo =1;

    // Get Main Table record number
    dREC04RECNUMTYP dMainTabRecNo = oDxfDb.getMainTabRecNo(0,eEntityType,dEntRecNo);
    assert(dMainTabRecNo > 0);

    // Get Section Entities record number, is main table record number minus all block records
    dREC04RECNUMTYP dSectEntRecNo = oDxfDb.getSectEntRecNo(0,eEntityType,dEntRecNo);
    assert(dSectEntRecNo > 0);

    // Count Blocks in database
    // return number of blocks in sstDxfDb
    dREC04RECNUMTYP dNumBlocks = oDxfDb.countBlocks();
    // Modelspace, Paperspace, Sym1, Sym2
    assert(dNumBlocks == 4);

    for (dREC04RECNUMTYP ll=1; ll <= dNumBlocks; ll++)
    {
      // Read block from table with attributes
      DL_BlockData    oDLBlock("",0,0.0,0.0,0.0);
      DL_Attributes   oDLAttributes;
      iStat = oDxfDb.ReadBlock ( 0, ll, &oDLBlock, &oDLAttributes);
      assert (iStat == 0);

      // return number of entities in actual block in sstDxfDb
      dREC04RECNUMTYP dNumEntities = oDxfDb.countEntities (0, ll);
      // assert(dNumEntities >= 0);
      if (dNumEntities > 0)
      {

      // return start of entities of actual block in Main table
      dREC04RECNUMTYP dStartBlkMainTab = oDxfDb.getBlkStartMainTab (0, ll);
      assert(dStartBlkMainTab > 0);
      // Loop over all entities of actual block
      for (dREC04RECNUMTYP kk = dStartBlkMainTab; kk <= dStartBlkMainTab+dNumEntities; kk++)
      {
        iStat = oDxfDb.ReadMainTable( 0, kk, &eEntityType, &dEntRecNo);
        assert(iStat >= 0);
        switch (eEntityType) {
        case RS2::EntityCircle:
        {
          DL_CircleData oCircleRec(0,0,0,1);    // Entity Circle from dxflib
          DL_Attributes oAttribRec;
          iStat = oDxfDb.ReadCircle(0,dEntRecNo,&oCircleRec,&oAttribRec);
        }
          break;
        case RS2::EntityUnknown:
          break;
        default:
          break;
        }  // end switch
        assert(iStat >= 0);
      }
      } // if dNumEntities > 0
    }

    dREC04RECNUMTYP dBlkNo = oDxfDb.searchBlkNoWithName(0,"Sym1");
    assert(dBlkNo == 3);
    dBlkNo = oDxfDb.searchBlkNoWithName(0,"Sym2");
    assert(dBlkNo == 4);
    dBlkNo = oDxfDb.searchBlkNoWithName(0,"SymX");
    assert(dBlkNo == 0);

    // Write Database to group for csv files
    oDxfDb.WritAll2Csv(0,"Test_Utm.dxf");

    // Write dxf database to dxf file
    oDxfDb.WritAll2DxfFil(0,"Test_Utm.dxf");

    oPrt.SST_PrtWrt(1,(char*)"Creating Test_Utm.dxf");
  }

  {
    // Open new sstDxf Database
    sstDxf03DbCls oDxfDB(&oPrt);

    // Read contents of dxf file into sstDxf database
    iStat = oDxfDB.ReadAllFromDxf(0,"Test_Utm.dxf");
    assert(iStat >= 0);

//    // Get Minimum Bounding rectangle from section entities /model space
//    sstMath01Mbr2Cls oMbrModel = oDxfDB.getMbrModel();

//    // Test Minimum Bounding rectangle from testfile test.dxf, which is created by
//    // testframe function -testwriting-
//    if (oMbrModel.getXI() != 10.0) assert(0);
//    if (oMbrModel.getYI() != 30.0) assert(0);
//    if (oMbrModel.getXA() != 100.0) assert(0);
//    if (oMbrModel.getYA() != 120.0) assert(0);

    // Write dxf database to dxf file
    iStat = oDxfDB.WritAll2DxfFil(0,"Test_Utm2.dxf");
    assert(iStat >= 0);

    iStat = sstMisc01FileCompare( 1,"Test_Utm.dxf","Test_Utm2.dxf",&ulRowNo);
    if (iStat != 0)
    {
        // assert(ulRowNo == 1230);  // Problem with handle 340 in DIMSTYLE
        assert(ulRowNo == 1492);  // Problem with handle 340 in DIMSTYLE
    }

    oPrt.SST_PrtWrt(1,(char*)"Compare Test_Utm.dxf / Test_Utm2.dxf OK");
    oPrt.SST_PrtWrt(1,(char*)"  ");

  } // Close sstDxf Database


  // Call extended Test dxflib writing function
  // See dxflib writing example
  // Write full block objects and use with inserts
  iStat = testWriting2("Test5.dxf");
  assert(iStat >= 0);

  // Call Test dxflib writing function
  // See dxflib writing example
  iStat = testWriting("Test.dxf");
  assert(iStat >= 0);

  oPrt.SST_PrtWrt(1,(char*)"Creating Test.dxf with dxflib Testwriting function");

  {
    // Open new sstDxf Database
    sstDxf03DbCls oDxfDB(&oPrt);

    // Read contents of dxf file into sstDxf database
    iStat = oDxfDB.ReadAllFromDxf(0,"Test.dxf");
    assert(iStat >= 0);

    // Get Minimum Bounding rectangle from section entities /model space
    sstMath01Mbr2Cls oMbrModel = oDxfDB.getMbrModel();

    // Test Minimum Bounding rectangle from testfile test.dxf, which is created by
    // testframe function -testwriting-
    if (oMbrModel.getXI() != 10.0) assert(0);
    if (oMbrModel.getYI() != 30.0) assert(0);
    if (oMbrModel.getXA() != 100.0) assert(0);
    if (oMbrModel.getYA() != 120.0) assert(0);

    // Write dxf database to dxf file
    iStat = oDxfDB.WritAll2DxfFil(0,"Test2.dxf");
    assert(iStat >= 0);

    iStat = sstMisc01FileCompare( 1,"Test.dxf","Test2.dxf",&ulRowNo);
    if (iStat != 0)
    {
        // assert(ulRowNo == 1230);  // Problem with handle 340 in DIMSTYLE
        assert(ulRowNo == 886);  // Problem with handle 340 in DIMSTYLE
    }

    oPrt.SST_PrtWrt(1,(char*)"Compare Test.dxf / Test2.dxf OK");
    oPrt.SST_PrtWrt(1,(char*)"  ");

    // Write dxf database to csv files
    iStat = oDxfDB.WritAll2Csv(0,"Test3.dxf");
    assert(iStat >= 0);

  } // Close sstDxf Database

  {
    // Open new sstDxf Database and read data from test3 csv files
    sstDxf03DbCls oDxfDB2(&oPrt);
    iStat = oDxfDB2.ReadAllCsvFiles(0,"Test3.dxf");
    assert(iStat >= 0);

    // write dxf database to dxf file
    iStat = oDxfDB2.WritAll2DxfFil(0,"Test3.dxf");
    assert(iStat >= 0);

    iStat = sstMisc01FileCompare( 1,"Test.dxf","Test3.dxf",&ulRowNo);
    if (iStat != 0)
    {
      // assert(ulRowNo == 886);  // Problem with handle 340 in DIMSTYLE
    }

    oPrt.SST_PrtWrt(1,(char*)"Compare Test.dxf / Test3.dxf OK");
    oPrt.SST_PrtWrt(1,(char*)"  ");

  }

  {
    // write new circle (border)
    DL_CircleData oDLCircle(0,0,0,1);
    DL_Attributes oAttributes;
    dREC04RECNUMTYP oEntRecNo = 0;
    dREC04RECNUMTYP oMainRecNo = 0;
    oAttributes.setLayer("0");
    oAttributes.setLinetype("CONTINUOUS");

    // Open new sstDxf Database
    sstDxf03DbCls oDxfDB(&oPrt);

    // Write new DL Circle object to sst dxf database
    iStat = oDxfDB.WriteNewCircle( 0, oDLCircle, oAttributes, &oEntRecNo, &oMainRecNo);
    assert(iStat >= 0);


    //=== Insert filled circle area
    {
      oAttributes.setColor(1);

      DL_HatchData oDLHatch(1,1,1,0,"SOLID");
      DL_HatchEdgeData oDLHatchEdge(3,3,1,0,2*M_PI,1);  // Circle

      // open new dxflib hatch object in sstDxfDb
      iStat = oDxfDB.OpenNewHatch( 0, oDLHatch, oAttributes, &oEntRecNo, &oMainRecNo);

      // write new dxflib hatch edge into sstDxfDb hatch object
      iStat = oDxfDB.WriteNewHatchEdge ( 0, oDLHatchEdge, &oEntRecNo, &oMainRecNo);
    }

    // Testframe for writing functions <BR>
    iStat = Test_WriteInterface ( 0, &oDxfDB);
    assert(iStat >= 0);

    //=== Insert filled triangel area
//    {
//      oAttributes.setColor(2);

//      DL_HatchData oDLHatch(1,1,1,0,"SOLID");

//      // open new dxflib hatch object in sstDxfDb
//      iStat = oDxfDB.OpenNewHatch( 0, oDLHatch, oAttributes, &oEntRecNo, &oMainRecNo);

//      DL_HatchEdgeData oDLHatchEdge(1,1,2,2);  // area border point
//      // write new dxflib hatch edge into sstDxfDb hatch object
//      iStat = oDxfDB.WriteNewHatchEdge ( 0, oDLHatchEdge, &oEntRecNo, &oMainRecNo);

//      // write new dxflib hatch edge into sstDxfDb hatch object
//      oDLHatchEdge.x1 = 2.0;oDLHatchEdge.y1 = 2.0;oDLHatchEdge.x2 = 1.0;oDLHatchEdge.y2 = 2.0;
//      iStat = oDxfDB.WriteNewHatchEdge ( 0, oDLHatchEdge, &oEntRecNo, &oMainRecNo);

//      // write new dxflib hatch edge into sstDxfDb hatch object
//      oDLHatchEdge.x1 = 1.0;oDLHatchEdge.y1 = 2.0;oDLHatchEdge.x2 = 1.0;oDLHatchEdge.y2 = 1.0;
//      iStat = oDxfDB.WriteNewHatchEdge ( 0, oDLHatchEdge, &oEntRecNo, &oMainRecNo);
//    }

    // Write dxf database to dxf file
    oDxfDB.WritAll2Csv(0,"Test4.dxf");
    oDxfDB.WritAll2DxfFil(0,"Test4.dxf");
  }

  {
    // Open new sstDxf Database
    sstDxf03DbCls oDxfDB(&oPrt);

    // import content of dxf file into sstDxf database
    iStat = oDxfDB.ReadAllFromDxf(0,"Test4.dxf");
    assert(iStat >= 0);

    dREC04RECNUMTYP dEntRecs = 0;
    dREC04RECNUMTYP dMainRecs = 0;

    dMainRecs = oDxfDB.MainCount();
    assert(dMainRecs == 25);

    dEntRecs = oDxfDB.EntityCount(RS2::EntityHatch);
    assert(dEntRecs == 3);

    DL_HatchData oDLHatch(1,1,1,0,"SOLID");
    DL_HatchEdgeData oDLHatchEdge(1,1,2,2);  // area border point
    DL_HatchLoopData oDLHatchLoop(1);  // outer or inner border
    DL_Attributes oDLAttributes;

    dREC04RECNUMTYP dRecNo = 1;
    iStat = oDxfDB.ReadHatch( 0, dRecNo, &oDLHatch, &oDLAttributes);
    iStat = oDxfDB.ReadHatchEdge( 0, dRecNo, &oDLHatchEdge);
    iStat = oDxfDB.ReadHatchLoop( 0, dRecNo, &oDLHatchLoop);

    // Read information from main table
    RS2::EntityType eEntType = RS2::EntityUnknown;
    iStat = oDxfDB.ReadMainTable(0,1,&eEntType,&dRecNo);
    assert(eEntType == RS2::EntityCircle);  // first entity is circle
    assert (dRecNo == 1);

  }

  {
    // Open new sstDxf Database and read data from test5 csv files
    sstDxf03DbCls oDxfDB2(&oPrt);
    iStat = oDxfDB2.ReadAllFromDxf(0,"Test5.dxf");
    assert(iStat >= 0);

    // write dxf database to dxf file
    iStat = oDxfDB2.WritAll2DxfFil(0,"Test6.dxf");
    assert(iStat >= 0);

    iStat = sstMisc01FileCompare( 1,"Test5.dxf","Test6.dxf",&ulRowNo);
    if (iStat != 0)
    {
      assert(ulRowNo == 898);  // Problem with handle 340 in DIMSTYLE
    }

    oPrt.SST_PrtWrt(1,(char*)"Compare Test5.dxf / Test6.dxf OK");
    oPrt.SST_PrtWrt(1,(char*)"  ");

  }
  iStat = oPrt.SST_PrtZu(1);

  return 0;
}
//=============================================================================
int testWriting(const std::string oDxfFilNam) {
    DL_Dxf* dxf = new DL_Dxf();
    DL_Codes::version exportVersion = DL_Codes::AC1015;
    // DL_WriterA* dw = dxf->out("myfile.dxf", exportVersion);
    DL_WriterA* dw = dxf->out( oDxfFilNam.c_str(), exportVersion);
    if (dw==NULL) {
        printf("Cannot open file 'myfile.dxf' \
               for writing.");
        return -1;
        // abort function e.g. with return
    }
    dxf->writeHeader(*dw);
    // int variable:
    dw->dxfString(9, "$INSUNITS");
    dw->dxfInt(70, 4);
    // real (double, float) variable:
    dw->dxfString(9, "$DIMEXE");
    dw->dxfReal(40, 1.25);
    // string variable:
    dw->dxfString(9, "$TEXTSTYLE");
    dw->dxfString(7, "Standard");
    // vector variable:
    dw->dxfString(9, "$LIMMIN");
    dw->dxfReal(10, 0.0);
    dw->dxfReal(20, 0.0);
    dw->sectionEnd();
    dw->sectionTables();
    dxf->writeVPort(*dw);
    dw->tableLinetypes(25);
    dxf->writeLinetype(*dw, DL_LinetypeData("BYBLOCK", "Description", 0, 0, 0.0));
    dxf->writeLinetype(*dw, DL_LinetypeData("BYLAYER", "Description", 0, 0, 0.0));
    dxf->writeLinetype(*dw, DL_LinetypeData("CONTINUOUS", "Description",0, 0, 0.0));
    dxf->writeLinetype(*dw, DL_LinetypeData("ACAD_ISO02W100", "Description", 0, 0, 0.0));
    dxf->writeLinetype(*dw, DL_LinetypeData("ACAD_ISO03W100", "Description", 0, 0, 0.0));
    dxf->writeLinetype(*dw, DL_LinetypeData("ACAD_ISO04W100", "Description", 0, 0, 0.0));
    dxf->writeLinetype(*dw, DL_LinetypeData("ACAD_ISO05W100", "Description", 0, 0, 0.0));
    dxf->writeLinetype(*dw, DL_LinetypeData("BORDER", "Description", 0, 0, 0.0));
    dxf->writeLinetype(*dw, DL_LinetypeData("BORDER2", "Description", 0, 0, 0.0));
    dxf->writeLinetype(*dw, DL_LinetypeData("BORDERX2", "Description", 0, 0, 0.0));
    dxf->writeLinetype(*dw, DL_LinetypeData("CENTER", "Description", 0, 0, 0.0));
    dxf->writeLinetype(*dw, DL_LinetypeData("CENTER2", "Description", 0, 0, 0.0));
    dxf->writeLinetype(*dw, DL_LinetypeData("CENTERX2", "Description", 0, 0, 0.0));
    dxf->writeLinetype(*dw, DL_LinetypeData("DASHDOT", "Description", 0, 0, 0.0));
    dxf->writeLinetype(*dw, DL_LinetypeData("DASHDOT2", "Description", 0, 0, 0.0));
    dxf->writeLinetype(*dw, DL_LinetypeData("DASHDOTX2", "Description", 0, 0, 0.0));
    dxf->writeLinetype(*dw, DL_LinetypeData("DASHED", "Description", 0, 0, 0.0));
    dxf->writeLinetype(*dw, DL_LinetypeData("DASHED2", "Description", 0, 0, 0.0));
    dxf->writeLinetype(*dw, DL_LinetypeData("DASHEDX2", "Description", 0, 0, 0.0));
    dxf->writeLinetype(*dw, DL_LinetypeData("DIVIDE", "Description", 0, 0, 0.0));
    dxf->writeLinetype(*dw, DL_LinetypeData("DIVIDE2", "Description", 0, 0, 0.0));
    dxf->writeLinetype(*dw, DL_LinetypeData("DIVIDEX2", "Description", 0, 0, 0.0));
    dxf->writeLinetype(*dw, DL_LinetypeData("DOT", "Description", 0, 0, 0.0));
    dxf->writeLinetype(*dw, DL_LinetypeData("DOT2", "Description", 0, 0, 0.0));
    dxf->writeLinetype(*dw, DL_LinetypeData("DOTX2", "Description", 0, 0, 0.0));
    dw->tableEnd();
    int numberOfLayers = 3;
    dw->tableLayers(numberOfLayers);

    double dLineTypeScale = 1.0;
    dxf->writeLayer(*dw,
                   DL_LayerData("0", 0),
                   DL_Attributes(
                       std::string(""),      // leave empty
                       DL_Codes::black,        // default color
                       100,                  // default width
                       "CONTINUOUS", dLineTypeScale));       // default line style

    dxf->writeLayer(*dw,
                   DL_LayerData("mainlayer", 0),
                   DL_Attributes(
                       std::string(""),
                       DL_Codes::red,
                       100,
                       "CONTINUOUS", dLineTypeScale));

    dxf->writeLayer(*dw,
                   DL_LayerData("anotherlayer", 0),
                   DL_Attributes(
                       std::string(""),
                       DL_Codes::black,
                       100,
                       "CONTINUOUS", dLineTypeScale));

    dw->tableEnd();

    dw->tableStyle(1);
    dxf->writeStyle(*dw, DL_StyleData("standard", 0, 2.5, 1.0, 0.0, 0, 2.5, "txt", ""));
    dw->tableEnd();

    // dxf->writeStyle(*dw, DL_StyleData("standard", 0, 2.5, 1.0, 0.0, 0, 2.5, "standard", ""));
    dxf->writeView(*dw);
    dxf->writeUcs(*dw);

    dw->tableAppid(1);
    dw->tableAppidEntry(0x12);
    dw->dxfString(2, "ACAD");
    dw->dxfInt(70, 0);
    dw->tableEnd();
    dxf->writeDimStyle(*dw,
                      1,
                      1,
                      1,
                      1,
                      1);
    dxf->writeBlockRecord(*dw);
    dxf->writeBlockRecord(*dw, "myblock1");
    dxf->writeBlockRecord(*dw, "myblock2");
    dw->tableEnd();
    dw->sectionEnd();
    dw->sectionBlocks();

    dxf->writeBlock(*dw,
                   DL_BlockData("*Model_Space", 0, 0.0, 0.0, 0.0));
    dxf->writeEndBlock(*dw, "*Model_Space");

    dxf->writeBlock(*dw,
                   DL_BlockData("*Paper_Space", 0, 0.0, 0.0, 0.0));
    dxf->writeEndBlock(*dw, "*Paper_Space");

    dxf->writeBlock(*dw,
                   DL_BlockData("*Paper_Space0", 0, 0.0, 0.0, 0.0));
    dxf->writeEndBlock(*dw, "*Paper_Space0");

    dxf->writeBlock(*dw,
                   DL_BlockData("myblock1", 0, 0.0, 0.0, 0.0));
    // ...
    // write block entities e.g. with dxf->writeLine(), ..
    // ...
    dxf->writeEndBlock(*dw, "myblock1");

    dxf->writeBlock(*dw,
                   DL_BlockData("myblock2", 0, 0.0, 0.0, 0.0));
    // ...
    // write block entities e.g. with dxf->writeLine(), ..
    // ...
    dxf->writeEndBlock(*dw, "myblock2");

    dw->sectionEnd();
    dw->sectionEntities();

    // write all your entities..
    double dLinetypeScale = 1.0;
    dxf->writePoint(
        *dw,
        DL_PointData(10.0,
                     45.0,
                     0.0),
        DL_Attributes("mainlayer", 256, -1, "BYLAYER", dLinetypeScale));

    dxf->writeLine(
        *dw,
        DL_LineData(25.0,   // start point
                    30.0,
                    0.0,
                    100.0,   // end point
                    120.0,
                    0.0),
        DL_Attributes("mainlayer", 256, -1, "BYLAYER", dLinetypeScale));

    dw->sectionEnd();
    dxf->writeObjects(*dw);
    dxf->writeObjectsEnd(*dw);
    dw->dxfEOF();
    dw->close();
    delete dw;
    delete dxf;
    return 0;
}
//=============================================================================
int testWriting2 (const std::string oDxfFilNam) {
    DL_Dxf* dxf = new DL_Dxf();
    DL_Codes::version exportVersion = DL_Codes::AC1015;
    // DL_WriterA* dw = dxf->out("myfile.dxf", exportVersion);
    DL_WriterA* dw = dxf->out( oDxfFilNam.c_str(), exportVersion);
    if (dw==NULL) {
        printf("Cannot open file 'myfile.dxf' \
               for writing.");
        return -1;
        // abort function e.g. with return
    }
    dxf->writeHeader(*dw);
    // int variable:
    dw->dxfString(9, "$INSUNITS");
    dw->dxfInt(70, 4);
    // real (double, float) variable:
    dw->dxfString(9, "$DIMEXE");
    dw->dxfReal(40, 1.25);
    // string variable:
    dw->dxfString(9, "$TEXTSTYLE");
    dw->dxfString(7, "Standard");
    // vector variable:
    dw->dxfString(9, "$LIMMIN");
    dw->dxfReal(10, 0.0);
    dw->dxfReal(20, 0.0);
    dw->sectionEnd();
    dw->sectionTables();
    dxf->writeVPort(*dw);
    dw->tableLinetypes(25);
    dxf->writeLinetype(*dw, DL_LinetypeData("BYBLOCK", "Description", 0, 0, 0.0));
    dxf->writeLinetype(*dw, DL_LinetypeData("BYLAYER", "Description", 0, 0, 0.0));
    dxf->writeLinetype(*dw, DL_LinetypeData("CONTINUOUS", "Description", 0, 0, 0.0));
    dxf->writeLinetype(*dw, DL_LinetypeData("ACAD_ISO02W100", "Description", 0, 0, 0.0));
    dxf->writeLinetype(*dw, DL_LinetypeData("ACAD_ISO03W100", "Description", 0, 0, 0.0));
    dxf->writeLinetype(*dw, DL_LinetypeData("ACAD_ISO04W100", "Description", 0, 0, 0.0));
    dxf->writeLinetype(*dw, DL_LinetypeData("ACAD_ISO05W100", "Description", 0, 0, 0.0));
    dxf->writeLinetype(*dw, DL_LinetypeData("BORDER", "Description", 0, 0, 0.0));
    dxf->writeLinetype(*dw, DL_LinetypeData("BORDER2", "Description", 0, 0, 0.0));
    dxf->writeLinetype(*dw, DL_LinetypeData("BORDERX2", "Description", 0, 0, 0.0));
    dxf->writeLinetype(*dw, DL_LinetypeData("CENTER", "Description", 0, 0, 0.0));
    dxf->writeLinetype(*dw, DL_LinetypeData("CENTER2", "Description", 0, 0, 0.0));
    dxf->writeLinetype(*dw, DL_LinetypeData("CENTERX2", "Description", 0, 0, 0.0));
    dxf->writeLinetype(*dw, DL_LinetypeData("DASHDOT", "Description", 0, 0, 0.0));
    dxf->writeLinetype(*dw, DL_LinetypeData("DASHDOT2", "Description", 0, 0, 0.0));
    dxf->writeLinetype(*dw, DL_LinetypeData("DASHDOTX2", "Description", 0, 0, 0.0));
    dxf->writeLinetype(*dw, DL_LinetypeData("DASHED", "Description", 0, 0, 0.0));
    dxf->writeLinetype(*dw, DL_LinetypeData("DASHED2", "Description", 0, 0, 0.0));
    dxf->writeLinetype(*dw, DL_LinetypeData("DASHEDX2", "Description", 0, 0, 0.0));
    dxf->writeLinetype(*dw, DL_LinetypeData("DIVIDE", "Description", 0, 0, 0.0));
    dxf->writeLinetype(*dw, DL_LinetypeData("DIVIDE2", "Description", 0, 0, 0.0));
    dxf->writeLinetype(*dw, DL_LinetypeData("DIVIDEX2", "Description", 0, 0, 0.0));
    dxf->writeLinetype(*dw, DL_LinetypeData("DOT", "Description", 0, 0, 0.0));
    dxf->writeLinetype(*dw, DL_LinetypeData("DOT2", "Description", 0, 0, 0.0));
    dxf->writeLinetype(*dw, DL_LinetypeData("DOTX2", "Description", 0, 0, 0.0));
    dw->tableEnd();
    int numberOfLayers = 3;
    dw->tableLayers(numberOfLayers);

    double dLinetypeScale = 1.0;
    dxf->writeLayer(*dw,
                   DL_LayerData("0", 0),
                   DL_Attributes(
                       std::string(""),      // leave empty
                       DL_Codes::black,        // default color
                       100,                  // default width
                       "CONTINUOUS", dLinetypeScale));       // default line style

    dxf->writeLayer(*dw,
                   DL_LayerData("mainlayer", 0),
                   DL_Attributes(
                       std::string(""),
                       DL_Codes::red,
                       100,
                       "CONTINUOUS", dLinetypeScale));

    dxf->writeLayer(*dw,
                   DL_LayerData("anotherlayer", 0),
                   DL_Attributes(
                       std::string(""),
                       DL_Codes::black,
                       100,
                       "CONTINUOUS", dLinetypeScale));

    dw->tableEnd();
    dw->tableStyle(1);
    dxf->writeStyle(*dw, DL_StyleData("standard", 0, 2.5, 1.0, 0.0, 0, 2.5, "txt", ""));
    dw->tableEnd();

    // dxf->writeStyle(*dw, DL_StyleData("standard", 0, 2.5, 1.0, 0.0, 0, 2.5, "standard", ""));
    dxf->writeView(*dw);
    dxf->writeUcs(*dw);

    dw->tableAppid(1);
    dw->tableAppidEntry(0x12);
    dw->dxfString(2, "ACAD");
    dw->dxfInt(70, 0);
    dw->tableEnd();
    dxf->writeDimStyle(*dw,
                      1,
                      1,
                      1,
                      1,
                      1);
    dxf->writeBlockRecord(*dw);
    dxf->writeBlockRecord(*dw, "myblock1");
    dxf->writeBlockRecord(*dw, "myblock2");
    dw->tableEnd();
    dw->sectionEnd();
    dw->sectionBlocks();

    dxf->writeBlock(*dw,
                   DL_BlockData("*Model_Space", 0, 0.0, 0.0, 0.0));
    dxf->writeEndBlock(*dw, "*Model_Space");

    dxf->writeBlock(*dw,
                   DL_BlockData("*Paper_Space", 0, 0.0, 0.0, 0.0));
    dxf->writeEndBlock(*dw, "*Paper_Space");

    dxf->writeBlock(*dw,
                   DL_BlockData("*Paper_Space0", 0, 0.0, 0.0, 0.0));
    dxf->writeEndBlock(*dw, "*Paper_Space0");

    dxf->writeBlock(*dw,
                   DL_BlockData("myblock1", 0, 0.0, 0.0, 0.0));
    // ...
    // write block entities e.g. with dxf->writeLine(), ..

    dxf->writeLine(
        *dw,
        DL_LineData(0.0,   // start point
                    0.0,
                    0.0,
                    10.0,   // end point
                    10.0,
                    0.0),
        DL_Attributes("myblock1", 256, -1, "BYBLOCK", dLinetypeScale));

    dxf->writeLine(
        *dw,
        DL_LineData(0.0,   // start point
                    10.0,
                    0.0,
                    10.0,   // end point
                    0.0,
                    0.0),
        DL_Attributes("myblock1", 256, -1, "BYBLOCK", dLinetypeScale));

    // ...
    dxf->writeEndBlock(*dw, "myblock1");

    dxf->writeBlock(*dw,
                   DL_BlockData("myblock2", 0, 0.0, 0.0, 0.0));
    // ...
    // write block entities e.g. with dxf->writeLine(), ..
    // ...
    dxf->writeEndBlock(*dw, "myblock2");

    dw->sectionEnd();
    dw->sectionEntities();

    // write all your entities..

    // write test point
    dxf->writePoint(
        *dw,
        DL_PointData(10.0,
                     45.0,
                     0.0),
        DL_Attributes("mainlayer", 256, -1, "BYLAYER", dLinetypeScale));

    // write test insert
    dxf->writeInsert(
        *dw,
        DL_InsertData("myblock1",25.0,30.0,0,1,1,1,0,1,1,0,0),
        DL_Attributes("mainlayer", 256, -1, "BYLAYER", dLinetypeScale));

    // write test line
    dxf->writeLine(
        *dw,
        DL_LineData(25.0,   // start point
                    30.0,
                    0.0,
                    100.0,   // end point
                    120.0,
                    0.0),
        DL_Attributes("mainlayer", 256, -1, "BYLAYER", dLinetypeScale));

    // dxf->writePolyline();

    // dxf->writePolylineEnd();

    dw->sectionEnd();
    dxf->writeObjects(*dw);
    dxf->writeObjectsEnd(*dw);
    dw->dxfEOF();
    dw->close();
    delete dw;
    delete dxf;
    return 0;
}
//=============================================================================
int Test_WriteInterface (int iKey, sstDxf03DbCls *poDxfDb)
//-----------------------------------------------------------------------------
{
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  // Write Hatch into sstDxf Database
  iStat = Test_WriteHatch ( iKey, poDxfDb, 5.0, 5.0);

  // Test Write Polyline into sstDxf Database
  iStat = Test_WritePolyline ( iKey, poDxfDb, 7.0, 5.0);

  // Write Hatch into sstDxf Database
  iStat = Test_WriteHatch ( iKey, poDxfDb, 9.0, 5.0);

  // Test Write Polyline into sstDxf Database
  iStat = Test_WritePolyline ( iKey, poDxfDb, 11.0, 5.0);

  //  Test Write Circle into sstDxf Database <BR>
  iStat = Test_WriteCircle ( iKey, poDxfDb, 13.0, 5.0);

  // Test Write Arc into sstDxf Database <BR>
  iStat = Test_WriteArc ( iKey, poDxfDb, 15.0, 5.0);

  // Test Write Text into sstDxf Database <BR>
  iStat = Test_WriteText ( iKey, poDxfDb, 17.0, 5.0);

  return iStat;
}
//=============================================================================
int Test_ReadInterface (int iKey, sstDxf03DbCls *oDxfDB)
//-----------------------------------------------------------------------------
{
  int iRet = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  // Fatal Errors goes to an assert
  assert(iRet >= 0);

  // Small Errors will given back
  iRet = iStat;

  return iRet;
}
//=============================================================================
int Test_WriteHatch (int iKey, sstDxf03DbCls *oDxfDB, const double dXX, const double dYY)
//-----------------------------------------------------------------------------
{
  DL_Attributes oAttributes;
  dREC04RECNUMTYP oEntRecNo = 0;
  dREC04RECNUMTYP oMainRecNo = 0;
  double dDist = 1.0;

  int iRet = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  oAttributes.setLayer("0");
  oAttributes.setLinetype("CONTINUOUS");

  //=== Insert filled triangel area
  {
    oAttributes.setColor(2);

    DL_HatchData oDLHatch(1,1,1,0,"SOLID");

    // open new dxflib hatch object in sstDxfDb
    iStat = oDxfDB->OpenNewHatch( 0, oDLHatch, oAttributes, &oEntRecNo, &oMainRecNo);

    DL_HatchEdgeData oDLHatchEdge(0,0,0,0);  // area border point
    // write new dxflib hatch edge into sstDxfDb hatch object
    oDLHatchEdge.x1 = dXX;         oDLHatchEdge.y1 = dYY;
    oDLHatchEdge.x2 = dXX + dDist; oDLHatchEdge.y2 = dYY + dDist;
    iStat = oDxfDB->WriteNewHatchEdge ( 0, oDLHatchEdge, &oEntRecNo, &oMainRecNo);

    // write new dxflib hatch edge into sstDxfDb hatch object
    oDLHatchEdge.x1 = dXX + dDist; oDLHatchEdge.y1 = dYY + dDist;
    oDLHatchEdge.x2 = dXX + dDist; oDLHatchEdge.y2 = dYY;
    iStat = oDxfDB->WriteNewHatchEdge ( 0, oDLHatchEdge, &oEntRecNo, &oMainRecNo);

    // write new dxflib hatch edge into sstDxfDb hatch object
    oDLHatchEdge.x1 = dXX + dDist; oDLHatchEdge.y1 = dYY;
    oDLHatchEdge.x2 = dXX;         oDLHatchEdge.y2 = dYY;
    iStat = oDxfDB->WriteNewHatchEdge ( 0, oDLHatchEdge, &oEntRecNo, &oMainRecNo);
  }

  // Fatal Errors goes to an assert
  assert(iRet >= 0);

  // Small Errors will given back
  iRet = iStat;

  return iRet;
}
//=============================================================================
int Test_WritePolyline (int iKey, sstDxf03DbCls *oDxfDB, const double dXX, const double dYY)
//-----------------------------------------------------------------------------
{
  DL_Attributes oAttributes;
  dREC04RECNUMTYP oEntRecNo = 0;
  dREC04RECNUMTYP oMainRecNo = 0;
  double dDist = 1.0;

  int iRet = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  oAttributes.setLayer("0");
  oAttributes.setLinetype("CONTINUOUS");

  //=== Insert polyline
  {
    oAttributes.setColor(2);

    // DL_HatchData oDLHatch(1,1,1,0,"SOLID");
    DL_PolylineData oDlPolyline(0,0,0,0);
    DL_VertexData oDlVertex(0.0,0.0,0.0,0.0);

    // open new dxflib hatch object in sstDxfDb
    // iStat = oDxfDB->OpenNewHatch( 0, oDLHatch, oAttributes, &oEntRecNo, &oMainRecNo);
    iStat = oDxfDB->OpenNewPolyline( 0, oDlPolyline, oAttributes, &oEntRecNo, &oMainRecNo);

    // DL_HatchEdgeData oDLHatchEdge(1,1,2,2);  // area border point
    oDlVertex.x = dXX; oDlVertex.y = dYY; oDlVertex.z = 0.0;
    // write new dxflib hatch edge into sstDxfDb hatch object
    // iStat = oDxfDB->WriteNewHatchEdge ( 0, oDLHatchEdge, &oEntRecNo, &oMainRecNo);
    iStat = oDxfDB->WriteNewVertex ( 0, oDlVertex, &oEntRecNo, &oMainRecNo);

    // write new dxflib hatch edge into sstDxfDb hatch object
    // oDLHatchEdge.x1 = 2.0;oDLHatchEdge.y1 = 2.0;oDLHatchEdge.x2 = 1.0;oDLHatchEdge.y2 = 2.0;
    oDlVertex.x = dXX + dDist; oDlVertex.y = dYY; oDlVertex.z = 0.0;
    // iStat = oDxfDB->WriteNewHatchEdge ( 0, oDLHatchEdge, &oEntRecNo, &oMainRecNo);
    iStat = oDxfDB->WriteNewVertex ( 0, oDlVertex, &oEntRecNo, &oMainRecNo);

    // write new dxflib hatch edge into sstDxfDb hatch object
    // oDLHatchEdge.x1 = 1.0;oDLHatchEdge.y1 = 2.0;oDLHatchEdge.x2 = 1.0;oDLHatchEdge.y2 = 1.0;
    oDlVertex.x = dXX + dDist; oDlVertex.y = dYY + dDist; oDlVertex.z = 0.0;
    // iStat = oDxfDB->WriteNewHatchEdge ( 0, oDLHatchEdge, &oEntRecNo, &oMainRecNo);
    iStat = oDxfDB->WriteNewVertex ( 0, oDlVertex, &oEntRecNo, &oMainRecNo);
  }

  // Fatal Errors goes to an assert
  assert(iRet >= 0);

  // Small Errors will given back
  iRet = iStat;

  return iRet;
}
//=============================================================================
int Test_WriteCircle (int iKey, sstDxf03DbCls *oDxfDB, const double dXX, const double dYY)
//-----------------------------------------------------------------------------
{
  DL_Attributes oAttributes;
  dREC04RECNUMTYP oEntRecNo = 0;
  dREC04RECNUMTYP oMainRecNo = 0;
  double dDist = 0.5;

  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  oAttributes.setLayer("0");
  oAttributes.setLinetype("CONTINUOUS");

  oAttributes.setColor(2);

  //=== Insert Circle
  DL_CircleData oDLCircle( dXX, dYY, 0, dDist);  // Radius = 1

  // Write new DL Circle object to sst dxf database
  iStat = oDxfDB->WriteNewCircle( 0, oDLCircle, oAttributes, &oEntRecNo, &oMainRecNo);
  assert(iStat >= 0);

  return iStat;
}
//=============================================================================
int Test_WriteArc (int iKey, sstDxf03DbCls *oDxfDB, const double dXX, const double dYY)
//-----------------------------------------------------------------------------
{
  DL_Attributes oAttributes;
  dREC04RECNUMTYP oEntRecNo = 0;
  dREC04RECNUMTYP oMainRecNo = 0;
  double dDist = 0.5;

  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  oAttributes.setLayer("0");
  oAttributes.setLinetype("CONTINUOUS");

  oAttributes.setColor(2);

  //=== Insert Arc
  DL_ArcData oDlArc (dXX,dYY,0.0,dDist,0.0,100.0);  // Radius = 1

  // Write new DL Arc object to sst dxf database
  iStat = oDxfDB->WriteNewArc( 0, oDlArc, oAttributes, &oEntRecNo, &oMainRecNo);
  assert(iStat >= 0);

  return iStat;
}
//=============================================================================
int Test_WriteText (int iKey, sstDxf03DbCls *oDxfDB, const double dXX, const double dYY)
//-----------------------------------------------------------------------------
{
  DL_Attributes oAttributes;
  dREC04RECNUMTYP oEntRecNo = 0;
  dREC04RECNUMTYP oMainRecNo = 0;
  double dHeight = 1.0;
  double dAngle = 0.0;

  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  oAttributes.setLayer("0");
  oAttributes.setLinetype("CONTINUOUS");

  oAttributes.setColor(2);

  //=== Insert Text
  DL_TextData oDlText(dXX,dYY,0.0,0.0,0.0,0.0,dHeight,0.0,0,0,0,"Test","", dAngle);

  // Write new DL Circle object to sst dxf database
  iStat = oDxfDB->WriteText( 0, oDlText, oAttributes, &oEntRecNo, &oMainRecNo);
  assert(iStat >= 0);

  return iStat;
}
//=============================================================================
