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
// sstDxf03_fromCsv.cpp    18.11.16  Re.    18.11.16  Re.
//
// Tool converts csv table files together to a dxf drawing file.
// Merges layer csv file, block csv file, element arc csv file and so on ...
// Tool based on dxflib library.


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
#include <rs.h>

#include "sstDxf03_fromCsv.h"

//=============================================================================
int main(int argc, char** argv)
{
  sstMisc01PrtFilCls oPrt;
  std::string oDxfFilNam;
  int iStat = 0;

  // Open Protocol
  iStat = oPrt.SST_PrtAuf ( 1, (char*) "Csv2Dxf");
  assert(iStat == 0);

  // Check given arguments:
  if (argc < 2)
  {
    // Write Message to Protocolfile and console
    iStat = oPrt.SST_PrtWrtChar ( 1, (char*) "sstDxf03_fromCsv FileName.dxf", (char*) "Usage: ");

    // Close Protocol
    iStat = oPrt.SST_PrtZu ( 1);
    return 0;
  }

  oDxfFilNam = argv[1];

  sstDxf03DbCls oDxfDb(&oPrt);

  iStat = oDxfDb.ReadAllCsvFiles( 0, oDxfFilNam);
  assert(iStat == 0);

  iStat = oDxfDb.WritAll2DxfFil(0,oDxfFilNam);
  assert(iStat == 0);

    // Close Protocol
  iStat = oPrt.SST_PrtZu ( 1);
  return 0;
}
//=============================================================================
