# sst_dxf03_lib

sst_dxf03_lib extendes dxflib Entities with storing/database functions.
Eveny entity type is stored in sst table (github.com/UliRehr15/sst_rec04_lib).
For every dxf entity type like ARC, MTEXT and so on there is a table.
This sst dxf tables could be stored in memory or filesystem.
Exporting to csv is possible, so editing with spreedsheets
like excel could be done.

fork from sst_dxf02_lib: change license

change license to GNU General Public License version 2 because of use of LibreCAD.

Based on dxflib, extends dxflib
Uses functions from LibreCAD2

This Library is created with QtCreator 4.5.2 and gcc 7.3.0.

Structure of coding projects should be:

.. [libs]  <BR>
.. [boost_1_68_0]  from www.boost.org <BR>
.. [muParser]  Version 2.2.5 from https://github.com/beltoforion/muparser <BR>
.. [dxflib]  Version 3.12.2 from www.qcad.org/Download <BR>
   [sstLibreCAD2Lib]  <BR>
   [sst_str01_lib]  <BR>
   [sst_math01_lib]  <BR>
   [sst_misc01_lib]  <BR>
   [sst_rec04_lib]  <BR>
   [sst_dxf03_lib]  <BR>

28.02.16: Version 1.0: sst dxf lib: Tool Dxf2Csv: Realized: Layer Csv Table, Block Csv table, ARC Element Csv  <BR>
05.03.16: Version 1.1: Dxf2Csv: Arc Csv links to Layer Csv.  <BR>
05.03.16: Version 1.2: Dxf2Csv: Supports now INSERT element.  <BR>
10.03.16: Version 2.3: Change of Licence in according to librecad and dxflib. <BR>
                       Csv2Dxf: Tool frame and new table MAIN.  <BR>
29.04.16: Version 2.4: Tools Dxf2Csv and Csv2Dxf: Full support of ARC and INSERT.  <BR>
30.05.16: Version 2.5: Tool Dxf2Csv: Support of HATCH and POLYLINE.  <BR>
13.06.16: Version 2.6: Tool Csv2Dxf: Support of POLYLINE, extend support of attributes.  <BR>
17.06.16: Version 2.7: Tool Csv2Dxf: Support of HATCH.  <BR>
22.06.16: Version 2.8: General handling of layer/block data in entities.  <BR>
29.06.16: Version 2.9: Support for POLYLINE/HATCH in Block data.  <BR>
05.07.16: Version 2.10: Problems with color and width fixed.  <BR>
13.07.16: Version 2.11: new testframe for general testing.  <BR>
27.09.16: Version 2.12: Preparing works for entities circle, mtext, text. <BR>
21.10.16: Version 2.13: App Dxf2Csv: Full Support for circle, mtext, text. <BR>
28.10.16: Version 2.14: App Csv2Dxf: Full Support for circle, mtext, text. <BR>
                        Rise precision of decimal places to 4 for writing double values to csv <BR>
                        Caused by problems drawing filled circles in librecad. <BR>
25.11.16: Version 3.0: Redesign of user interface. hide implemetation details in library. <BR>
                       Support of entity types POINT and LINE. <BR>
                       Extent testframe with compare dxf after reading/writing. <BR>
23.12.16: Version 3.1: Support of entity types CIRCLE and HATCH. <BR>
21.05.17: Version 3.2: Add protocol events for import/export. <BR>
11.08.17: Version 3.3: Minimum Bounding Rectangle (Mbr)for dxf database. <BR>
23.02.18: Version 3.4: New function -ReadLINE-. <BR>
02.03.18: Version 3.5: New funktion -UpdateAttributesWithID. <BR>
09.03.18: Version 3.6: More Read-Functions for sstDxfDatabase.  <BR>
                       Calculate Mbr for block objects. <BR>
15.03.18: Version 3.7: New function -WriteLINE-. <BR>
18.03.18: Version 3.8: General functions -getMemberNames- for Type-Classes POINT, LINE, CIRCLE, MTEXT. <BR>
08.05.18: Version 3.9: Small improvements in Testframe and doxy help. <BR>
16.05.18: Version 3.10: Expand creating new dxf file with block infos and test writing/reading. <BR>
                        Fix error in function sstDxf03WriteCls::WrtSecBlocks. <BR>
25.05.18: Version 3.11: Extend entities in sstDxf03DatabaseCls::EntityCount. <BR>
13.06.18: Version 3.12: New entity D3Face. <BR>
25.06.18: Version 3.13: New entity Trace, lots of reads and writes for entities. <BR>
                        Added Type.def-File for sstDxf03. <BR>
25.06.18: Version 3.14: Fix problems in converting from dxf to csv and back. <BR>
21.09.18: Version 3.15: Updated to QtCreator 4.5.2 and gcc 7.3.0. <BR>
                        Updated to dxflib 3.12.2. <BR>
29.10.18: Version 3.16: New function ColumnCount for dxf database class. <BR>
31.10.18: Version 3.17: Added more Types in DxfType.def. <BR>
                        new functions getMemberNumber, getStringName, getStringTyp for many Dxf Types <BR>
01.11.18: Version 3.18: Forgotten to check in extended DxfType.Def file. <BR>
03.11.18: Version 3.19: new data generate function for all entitity types in utm coordinate system. <BR>
                        first realized for line, circle, hatch. <BR>
06.11.18: Version 3.20: class database write default blocks paperspace/modelspace in dxf file <BR>
16.11.18: Version 3.21: publish functions convert TypeEnum to string and viceversa. <BR>
                        Small corrections in looping over section entity objects .<BR>
14.12.18: Version 3.22: Back Pointer Functions inserted from Entity Table to Main Table. <BR>
                        Update Functions added after changing data. <BR>
21.12.18: Version 3.23: Database interface now supports creating blocks and insert entity. <BR>
                        Extend dxf generate data function with blocks and inserts for testing. <BR>
25.01.19: Version 3.24: Extend dxf generate data function with handling more blocks. <BR>
08.02.19: Version 3.25: Functions for reading, writing of block data. <BR>
22.02.19: Version 3.26: More general handling of ModelSpace/Paperspace Blocks. <BR>
                        Are now created by default with opening of dxf database. <BR>
23.02.19: Version 3.27: Add Name to intern entity insert. <BR>
15.03.19: Version 3.28: Better Support of GetMbr for all entities. <BR>
                        Read/Write Interface for Entity Polyline.  <BR>
16.03.19: Version 3.29: More Testing write hatch and polyline. <BR>
17.03.19: Version 3.30: Read/Write Interface for Entity Arc and Text. <BR>
26.03.19: Version 3.31: More Testing write Arc and Text. <BR>
                        Fixed some Errors in writing dxf. <BR>
28.03.19: Version 3.30: Read/Write Interface for Entity Point and MText. <BR>
05.04.19: Version 3.31: Fixed more Problems in writing group entities like LWPOLYLINE / HATCH. <BR>
22.04.19: Version 3.32: Some improvements in test writing and reading dxf files. <BR>
17.05.19: Version 3.33: Some improvements with handling Entitiy Mbr Data. <BR>
20.05.19: Version 3.34: Testframe for writing Entity Arc to Dxf File. <BR>
24.05.19: Version 3.35: Testframe for Entity Insert and Block. Fix problem in writing HatchEdge. <BR>
05.07.19: Version 3.36: New Function WriteVertex to DB. <BR>
                        fix problem in function ReadPolyline from Dxf. <BR>
17.09.19: Version 3.37: Fix problems with mbr of hatch. New function writeHatchEdge. <BR>
27.01.20: Version 3.38: More corrections in handling hatches in modelspace and blocks. <BR>
05.04.20: Version 3.39: New interface function ArcRead. <BR>
16.05.20: Version 3.40: Better support of True Colors (Color24). <BR>
21.12.20: Version 3.41: Fixed some doxygen warnings. <BR>
29.01.21: Version 3.42: Extend testing Arc entities with different angles/colors. <BR>

