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

#include "hex_blob/hex_blob.h"
#include <cstdint>
#include <cstdio>
#include <string>


void WriteDigit(const uint8_t byte, std::string* destination);

void WriteDigit(const uint8_t byte, std::string* dest) {
  if ( dest != NULL ) {
    char tmp[sizeof("0x00")];
    snprintf(tmp, sizeof(tmp), "0x%02X", byte);
    *dest += tmp;
  }
}

std::string ConvertBlobToHex(const uint8_t* blob, const size_t blob_length) {
  if (blob == NULL || blob_length == 0) {
    return std::string("");
  }

  std::string hex;
  for (size_t i = 0; i < blob_length; ++i) {
    WriteDigit(blob[i], &hex);
    if (i != blob_length-1) {
      hex += " ";
    }
  }

  return hex;
}

