/**********************************************************************
 *
 * sstDxf02Lib - sst dxf library
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
// sstDxf03_toCsv.cpp    25.06.18  Re.    18.11.16  Re.
//
// Tool splits dxf drawing file into object csv files.
// Csv file for layers, blocks, arc elements and so on ...
// Tool uses dxflib and librecad as base libraries.

#include <iostream>
#include <stdlib.h>
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

#include "sstDxf03_toCsv.h"

//=============================================================================
int main(int argc, char** argv)
{
  sstMisc01PrtFilCls oPrt;
  std::string oDxfFilNam;

  // Open Protocol
  int iStat = oPrt.SST_PrtAuf ( 1, (char*) "sstDxf03_toCsv.log");
  assert(iStat == 0);

    // Check given arguments:
    if (argc < 2)
    {
      // Write Message to Protocolfile and console
      iStat = oPrt.SST_PrtWrtChar ( 1, (char*) "sstDxf03_foCsv FileName.dxf", (char*) "Usage: ");

      // Close Protocol
      iStat = oPrt.SST_PrtZu ( 1);
      return 0;
    }

    sstDxf03DbCls oDxfDb(&oPrt);

    oDxfFilNam = argv[1];

    oDxfDb.ReadAllFromDxf( 0, oDxfFilNam);

    oDxfDb.WritAll2Csv(0, oDxfFilNam);

  // Close Protocol
  iStat = oPrt.SST_PrtZu ( 1);

  return 0;
}
//=============================================================================
/*
 * @brief Prints error message if file name not specified as command
 * line argument.
 */
void sstDxf2CsvCls::usage() {
    std::cout << "\nUsage: test <DXF file>\n\n";
}
//=============================================================================
sstDxf2CsvCls::sstDxf2CsvCls()
{

}
//=============================================================================
