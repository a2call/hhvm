HHVM_DEFINE_EXTENSION("spl"
  SOURCES
    ext_spl.cpp
  HEADERS
    ext_spl.h
  EXTENSION_LIBRARY
    ext_spl.php
  DEPENDS_UPON
    ext_std
    ext_string
    systemlib
)
