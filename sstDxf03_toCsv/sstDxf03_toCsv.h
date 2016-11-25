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
// sstDxf2Csv.h   26.02.16  Re.   26.02.16  Re.
//
// Datastructures and Prototypes for system "sstDxf01Lib"
//

#ifndef SSTDXF2CSV_HEADER
#define SSTDXF2CSV_HEADER

//==============================================================================
class sstDxf2CsvCls : public sstMisc01PrtFilCls
{
  public:   // Public functions
     sstDxf2CsvCls();  // Constructor
   //  ~sstDxf2CsvCls();  // Destructor
     //==============================================================================
     /**
     * @brief // Shortstory  <BR>
     *
     * @param iKey [in] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     void testReading(char* file);
     void usage();
     // sstMisc01PrtFilCls oPrt; /**< output protocol file */
// ----------------------------------------------------------------------------
  private:  // Private functions
};
//-----------------------------------------------------------------------------

#endif // SSTDXF2CSV_H

