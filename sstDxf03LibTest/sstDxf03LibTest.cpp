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
// sstdxf03LibTest.cpp    13.07.16  Re.    13.07.16  Re.
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
#include <sstMisc01Lib.h>
#include <sstRec04Lib.h>
#include <sstDxf03Lib.h>

#include "sstDxf03LibTest.h"

//=============================================================================
int main(int argc, char** argv)
{
  int iStat = 0;
  unsigned long ulRowNo = 0;

  // Call Test dxflib writing function
  // See dxflib writing example
  iStat = testWriting("Test.dxf");
  assert(iStat >= 0);

  sstMisc01PrtFilCls oPrt;
  oPrt.SST_PrtAuf(1,(char*)"sstDxf03LibTest.log");

  {
    // Open new sstDxf Database
    sstDxf03DbCls oDxfDB(&oPrt);

    // Read contents of dxf file into sstDxf database
    iStat = oDxfDB.ReadAllFromDxf(0,"Test.dxf");
    assert(iStat >= 0);

    // Write dxf database to dxf file
    iStat = oDxfDB.WritAll2DxfFil(0,"Test2.dxf");
    assert(iStat >= 0);

    // Write dxf database to csv files
    iStat = oDxfDB.WritAll2Csv(0,"Test3.dxf");
    assert(iStat >= 0);

    iStat = sstMisc01FileCompare(0,"Test.dxf","Test2.dxf",&ulRowNo);
    if (iStat != 0)
    {
      assert(ulRowNo == 1230);  // Problem with handle 340 in DIMSTYLE
    }

  } // Close śstDxf Database

  {
    // Open new sstDxf Database and read data from test3 csv files
    sstDxf03DbCls oDxfDB2(&oPrt);
    iStat = oDxfDB2.ReadAllCsvFiles(0,"Test3.dxf");
    assert(iStat >= 0);

    // write dxf database to dxf file
    iStat = oDxfDB2.WritAll2DxfFil(0,"Test3.dxf");
    assert(iStat >= 0);

    iStat = sstMisc01FileCompare(0,"Test.dxf","Test3.dxf",&ulRowNo);
    if (iStat != 0)
    {
      assert(ulRowNo == 1230);  // Problem with handle 340 in DIMSTYLE
    }
  }

  {
    // write new circle (border)
    DL_CircleData oDLCircle(0,0,0,1);
    DL_Attributes oAttributes;
    dREC04RECNUMTYP oEntRecNo = 0;
    dREC04RECNUMTYP oMainRecNo = 0;
    oAttributes.setLayer("0");
    oAttributes.setLineType("CONTINUOUS");

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

    //=== Insert filled triangel area
    {
      oAttributes.setColor(2);

      DL_HatchData oDLHatch(1,1,1,0,"SOLID");
      // open new dxflib hatch object in sstDxfDb
      iStat = oDxfDB.OpenNewHatch( 0, oDLHatch, oAttributes, &oEntRecNo, &oMainRecNo);

      DL_HatchEdgeData oDLHatchEdge(1,1,2,2);  // area border point
      // write new dxflib hatch edge into sstDxfDb hatch object
      iStat = oDxfDB.WriteNewHatchEdge ( 0, oDLHatchEdge, &oEntRecNo, &oMainRecNo);

      // write new dxflib hatch edge into sstDxfDb hatch object
      oDLHatchEdge.x1 = 2.0;oDLHatchEdge.y1 = 2.0;oDLHatchEdge.x2 = 1.0;oDLHatchEdge.y2 = 2.0;
      iStat = oDxfDB.WriteNewHatchEdge ( 0, oDLHatchEdge, &oEntRecNo, &oMainRecNo);

      // write new dxflib hatch edge into sstDxfDb hatch object
      oDLHatchEdge.x1 = 1.0;oDLHatchEdge.y1 = 2.0;oDLHatchEdge.x2 = 1.0;oDLHatchEdge.y2 = 1.0;
      iStat = oDxfDB.WriteNewHatchEdge ( 0, oDLHatchEdge, &oEntRecNo, &oMainRecNo);
    }

    // Write dxf database to dxf file
    oDxfDB.WritAll2Csv(0,"Test4.dxf");
    oDxfDB.WritAll2DxfFil(0,"Test4.dxf");
  }

  {
    // Open new sstDxf Database
    sstDxf03DbCls oDxfDB(&oPrt);

    // Read contents of dxf file into sstDxf database
    iStat = oDxfDB.ReadAllFromDxf(0,"Test4.dxf");
    assert(iStat >= 0);

    dREC04RECNUMTYP dEntRecs = 0;
    dREC04RECNUMTYP dMainRecs = 0;

    dMainRecs = oDxfDB.MainCount();
    assert(dMainRecs == 9);
    dEntRecs = oDxfDB.EntityCount(RS2::EntityHatch);
    assert(dEntRecs == 2);

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
    dw->tableLineTypes(25);
    dxf->writeLineType(*dw, DL_LineTypeData("BYBLOCK", 0));
    dxf->writeLineType(*dw, DL_LineTypeData("BYLAYER", 0));
    dxf->writeLineType(*dw,
                      DL_LineTypeData("CONTINUOUS", 0));
    dxf->writeLineType(*dw,
                      DL_LineTypeData("ACAD_ISO02W100", 0));
    dxf->writeLineType(*dw,
                      DL_LineTypeData("ACAD_ISO03W100", 0));
    dxf->writeLineType(*dw,
                      DL_LineTypeData("ACAD_ISO04W100", 0));
    dxf->writeLineType(*dw,
                      DL_LineTypeData("ACAD_ISO05W100", 0));
    dxf->writeLineType(*dw, DL_LineTypeData("BORDER", 0));
    dxf->writeLineType(*dw, DL_LineTypeData("BORDER2", 0));
    dxf->writeLineType(*dw, DL_LineTypeData("BORDERX2", 0));
    dxf->writeLineType(*dw, DL_LineTypeData("CENTER", 0));
    dxf->writeLineType(*dw, DL_LineTypeData("CENTER2", 0));
    dxf->writeLineType(*dw, DL_LineTypeData("CENTERX2", 0));
    dxf->writeLineType(*dw, DL_LineTypeData("DASHDOT", 0));
    dxf->writeLineType(*dw, DL_LineTypeData("DASHDOT2", 0));
    dxf->writeLineType(*dw,
                      DL_LineTypeData("DASHDOTX2", 0));
    dxf->writeLineType(*dw, DL_LineTypeData("DASHED", 0));
    dxf->writeLineType(*dw, DL_LineTypeData("DASHED2", 0));
    dxf->writeLineType(*dw, DL_LineTypeData("DASHEDX2", 0));
    dxf->writeLineType(*dw, DL_LineTypeData("DIVIDE", 0));
    dxf->writeLineType(*dw, DL_LineTypeData("DIVIDE2", 0));
    dxf->writeLineType(*dw,
                      DL_LineTypeData("DIVIDEX2", 0));
    dxf->writeLineType(*dw, DL_LineTypeData("DOT", 0));
    dxf->writeLineType(*dw, DL_LineTypeData("DOT2", 0));
    dxf->writeLineType(*dw, DL_LineTypeData("DOTX2", 0));
    dw->tableEnd();
    int numberOfLayers = 3;
    dw->tableLayers(numberOfLayers);

    dxf->writeLayer(*dw,
                   DL_LayerData("0", 0),
                   DL_Attributes(
                       std::string(""),      // leave empty
                       DL_Codes::black,        // default color
                       100,                  // default width
                       "CONTINUOUS"));       // default line style

    dxf->writeLayer(*dw,
                   DL_LayerData("mainlayer", 0),
                   DL_Attributes(
                       std::string(""),
                       DL_Codes::red,
                       100,
                       "CONTINUOUS"));

    dxf->writeLayer(*dw,
                   DL_LayerData("anotherlayer", 0),
                   DL_Attributes(
                       std::string(""),
                       DL_Codes::black,
                       100,
                       "CONTINUOUS"));

    dw->tableEnd();
    dxf->writeStyle(*dw, DL_StyleData("standard", 0, 2.5, 1.0, 0.0, 0, 2.5, "standard", ""));
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
    dxf->writePoint(
        *dw,
        DL_PointData(10.0,
                     45.0,
                     0.0),
        DL_Attributes("mainlayer", 256, -1, "BYLAYER"));

    dxf->writeLine(
        *dw,
        DL_LineData(25.0,   // start point
                    30.0,
                    0.0,
                    100.0,   // end point
                    120.0,
                    0.0),
        DL_Attributes("mainlayer", 256, -1, "BYLAYER"));

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
