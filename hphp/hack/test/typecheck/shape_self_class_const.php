<?hh

type MyShape = shape(Foo::KEY_NAME => int);

abstract class Foo {
  const string KEY_NAME = 'id1';
  public function printVal(MyShape $shape): int {
    return $shape[self::KEY_NAME];
  }
}
