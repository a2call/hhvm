HHVM_DEFINE_EXTENSION("mbstring"
  SOURCES
    ext_mbstring.cpp
  HEADERS
    ext_mbstring.h
    php_unicode.h
    unicode_data.h
  EXTENSION_LIBRARY
    ext_mbstring.php
  DEPENDS_UPON
    ext_process
    ext_std
    ext_string
    libMbfl
    libOniguruma
    systemlib
)
