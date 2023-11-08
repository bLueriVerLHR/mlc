top {
 @n = initializer 0 : int
 func.func @select_sort(%A : int[], %n : int) -> int {
  %i = initializer 0 : int
  %j = initializer 0 : int
  %min = initializer 0 : int
  %i = 0
  cf.while (comp.lth %i (sub %n 1)) loop {
   %min = %i
   %j = (add %i 1)
   cf.while (comp.lth %j %n) loop {
    cf.if (comp.gth %A[%min] %A[%j]) then {
     %min = %j
    }
    %j = (add %j 1)
   }
   cf.if (comp.neq %min %i) then {
    %tmp = initializer 0 : int
    %tmp = %A[%min]
    %A[%min] = %A[%i]
    %A[%i] = %tmp
   }
   %i = (add %i 1)
  }
  func.return 0
 }
 func.func @main() -> int {
  %n = 10
  %a = initializer [] : int[10]
  %a[0] = 4
  %a[1] = 3
  %a[2] = 9
  %a[3] = 2
  %a[4] = 0
  %a[5] = 1
  %a[6] = 6
  %a[7] = 5
  %a[8] = 7
  %a[9] = 8
  %i = initializer 0 : int
  %i = 0
  %i = func.call @select_sort(%a, %n)
  cf.while (comp.lth %i %n) loop {
   %tmp = initializer 0 : int
   %tmp = %a[%i]
   func.call @putint(%tmp)
   %tmp = 10
   func.call @putch(%tmp)
   %i = (add %i 1)
  }
  func.return 0
 }
}