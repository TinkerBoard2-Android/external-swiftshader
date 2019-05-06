; NOTE: Assertions have been autogenerated by utils/update_test_checks.py
; RUN: opt < %s -instsimplify -S | FileCheck %s

; Weird Types

define i129 @vec_extract_negidx(<3 x i129> %a) {
; CHECK-LABEL: @vec_extract_negidx(
; CHECK-NEXT:    ret i129 undef
;
  %E1 = extractelement <3 x i129> %a, i129 -1
  ret i129 %E1
}

define i129 @vec_extract_out_of_bounds(<3 x i129> %a) {
; CHECK-LABEL: @vec_extract_out_of_bounds(
; CHECK-NEXT:    ret i129 undef
;
  %E1 = extractelement <3 x i129> %a, i129 3
  ret i129 %E1
}

define i129 @vec_extract_out_of_bounds2(<3 x i129> %a) {
; CHECK-LABEL: @vec_extract_out_of_bounds2(
; CHECK-NEXT:    ret i129 undef
;
  %E1 = extractelement <3 x i129> %a, i129 999999999999999
  ret i129 %E1
}


define i129 @vec_extract_undef_index(<3 x i129> %a) {
; CHECK-LABEL: @vec_extract_undef_index(
; CHECK-NEXT:    ret i129 undef
;
  %E1 = extractelement <3 x i129> %a, i129 undef
  ret i129 %E1
}


define i129 @vec_extract_in_bounds(<3 x i129> %a) {
; CHECK-LABEL: @vec_extract_in_bounds(
; CHECK-NEXT:    %E1 = extractelement <3 x i129> %a, i129 2
; CHECK-NEXT:     ret i129 %E1
;
  %E1 = extractelement <3 x i129> %a, i129 2
  ret i129 %E1
}