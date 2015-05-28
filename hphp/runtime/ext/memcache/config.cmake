HHVM_EXTENSION_CHECK_DEPENDENCIES(memcache Libmemcached)
if (ENABLE_EXTENSION_MEMCACHE)
  HHVM_SELECT_SOURCES(HRE_CURRENT_EXT_PATH)
  message(STATUS "Building the memcache extension")
else()
  message("Not building the memcache extension")
endif()