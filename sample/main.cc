// Copyright 2013 Cristiano Prato

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include <cstdint>
#include <cstdio>
#include <string>
#include "hex_blob/hex_blob.h"
#include "hex_blob/version.h"

int main() {
  fprintf(stdout, "Running hex-blob version %s\n", kVersionStr.c_str());

  uint8_t blob[] = {0xD, 0xE, 0xA, 0xD};
  fprintf(stdout, "'%s'\n", ConvertBlobToHex(blob, sizeof(blob)).c_str());

  return 0;
}
