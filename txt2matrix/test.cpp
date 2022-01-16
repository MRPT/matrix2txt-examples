/* +---------------------------------------------------------------------------+
   |                     Mobile Robot Programming Toolkit (MRPT)               |
   |                          https://www.mrpt.org/                            |
   |                                                                           |
   | Copyright (c) 2005-2022, Individual contributors, see AUTHORS file        |
   | See: https://www.mrpt.org/Authors - All rights reserved.                  |
   | Released under BSD License. See details in https://www.mrpt.org/License   |
   +---------------------------------------------------------------------------+
 */

// Program: txt2matrix
//
// This demo program reads a TXT file and writes it as a mrpt::math::CMatrixF 
// object serialized into a binary file.

#include <iostream>
#include <mrpt/io/CFileGZOutputStream.h>
#include <mrpt/math/CMatrixF.h>
#include <mrpt/serialization/CArchive.h>
#include <mrpt/system/filesystem.h>

int main(int argc, char **argvv) {

  try {
    if (argc != 2) {
      std::cout << "Usage: " << argvv[0] << " <matrix_file.txt>\n";
      return 1;
    }

    const std::string file = argvv[1];
    std::cout << "Reading: " << file << "\n";

    mrpt::math::CMatrixF m;
    m.loadFromTextFile(file);

    const auto binFile = mrpt::system::fileNameChangeExtension(file, "bin.gz");
    std::cout << "Saving to: " << binFile << "\n";

    mrpt::io::CFileGZOutputStream f(binFile);
    auto arch = mrpt::serialization::archiveFrom(f);
    arch << m;

    return 0;
  } catch (const std::exception &e) {
    std::cerr << e.what();
    return 1;
  }
}
