rw_project('Substance')
	rw_default_location()
	rw_language_cpp()
	rw_kind_static_lib('Substance')

	rw_default_files()
	rw_default_includes()
	rw_precompiled_header()

	defines({
		macro_prefix .. 'COMPILE_LIBRARY=1',
	})
