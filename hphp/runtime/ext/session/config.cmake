HHVM_DEFINE_EXTENSION("session"
  SOURCES
    ext_session.cpp
  HEADERS
    ext_session.h
  EXTENSION_LIBRARY
    ext_session.php
  DEPENDS_UPON
    ext_hash
    ext_std
    ext_wddx
    libFolly
)
