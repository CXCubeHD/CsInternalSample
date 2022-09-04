file(GLOB_RECURSE CsInternalLoader-impl CONFIGURE_DEPENDS "*.cxx")
target_sources(CsInternalLoader PUBLIC ${CsInternalLoader-impl})