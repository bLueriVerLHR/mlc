{
 a = initializer 20 : const int
 b = initializer [1, 2] : int[6]
 c = initializer [1, 2] : int[52]
 func.func @main() -> int {
  r = initializer [] : int[240]
  func.return a
 }
}
