/* +---------------------------------------------------------------------------+
   |                     Mobile Robot Programming Toolkit (MRPT)               |
   |                          https://www.mrpt.org/                            |
   |                                                                           |
   | Copyright (c) 2005-2022, Individual contributors, see AUTHORS file        |
   | See: https://www.mrpt.org/Authors - All rights reserved.                  |
   | Released under BSD License. See details in https://www.mrpt.org/License   |
   +---------------------------------------------------------------------------+
 */

// Program: matrix2txt
//
// This demo program reads a mrpt::math::CMatrixF object serialized into a
// binary file and writes it as a TXT file, suitable to reading into
// Matlab/Octave, etc.

#include <iostream>
#include <mrpt/io/CFileGZInputStream.h>
#include <mrpt/io/CFileGZOutputStream.h>
#include <mrpt/math/CMatrixF.h>
#include <mrpt/serialization/CArchive.h>
#include <mrpt/system/filesystem.h>

int main(int argc, char **argvv) {

  try {
    if (argc != 2) {
      std::cout << "Usage: " << argvv[0] << " <matrix_file.bin>\n";
      return 1;
    }

    const std::string file = argvv[1];
    std::cout << "Reading: " << file << "\n";

    mrpt::math::CMatrixF m;

    mrpt::io::CFileGZInputStream f(file);
    auto arch = mrpt::serialization::archiveFrom(f);
    arch >> m;

    const auto txtFile = mrpt::system::fileNameChangeExtension(file, "txt");
    m.saveToTextFile(txtFile);

    std::cout << "Saving to: " << txtFile << "\n";

    return 0;
  } catch (const std::exception &e) {
    std::cerr << e.what();
    return 1;
  }
}
