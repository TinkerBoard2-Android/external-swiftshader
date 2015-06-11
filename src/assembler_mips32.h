//===- subzero/src/assembler_mips.h - Assembler for MIPS --------*- C++ -*-===//
//
// Copyright (c) 2013, the Dart project authors.  Please see the AUTHORS file
// for details. All rights reserved. Use of this source code is governed by a
// BSD-style license that can be found in the LICENSE file.
//
// Modified by the Subzero authors.
//
//===----------------------------------------------------------------------===//
//
//                        The Subzero Code Generator
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file implements the Assembler class for MIPS32.
//
//===----------------------------------------------------------------------===//

#ifndef SUBZERO_SRC_ASSEMBLER_MIPS32_H
#define SUBZERO_SRC_ASSEMBLER_MIPS32_H

#include "IceAssembler.h"
#include "IceDefs.h"
#include "IceFixups.h"

namespace Ice {
namespace MIPS32 {

class AssemblerMIPS32 : public Assembler {
  AssemblerMIPS32(const AssemblerMIPS32 &) = delete;
  AssemblerMIPS32 &operator=(const AssemblerMIPS32 &) = delete;

public:
  explicit AssemblerMIPS32(bool use_far_branches = false) : Assembler() {
    // This mode is only needed and implemented for MIPS32 and ARM.
    assert(!use_far_branches);
    (void)use_far_branches;
  }
  ~AssemblerMIPS32() override = default;

  void alignFunction() override {
    llvm::report_fatal_error("Not yet implemented.");
  }

  SizeT getBundleAlignLog2Bytes() const override { return 4; }

  const char *getNonExecPadDirective() const override { return ".TBD"; }

  llvm::ArrayRef<uint8_t> getNonExecBundlePadding() const override {
    llvm::report_fatal_error("Not yet implemented.");
  }

  void padWithNop(intptr_t Padding) override {
    (void)Padding;
    llvm::report_fatal_error("Not yet implemented.");
  }

  void bindCfgNodeLabel(SizeT NodeNumber) override {
    (void)NodeNumber;
    llvm::report_fatal_error("Not yet implemented.");
  }

  bool fixupIsPCRel(FixupKind Kind) const override {
    (void)Kind;
    llvm::report_fatal_error("Not yet implemented.");
  }
};

} // end of namespace MIPS32
} // end of namespace Ice

#endif // SUBZERO_SRC_ASSEMBLER_MIPS32_H
