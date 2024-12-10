rw_project('Tests')
	rw_default_location()
	rw_language_cpp()
	rw_kind_console_app('Tests')

	rw_default_files()
	rw_default_includes()
	rw_precompiled_header()

	-- Dependencies
	rw_link_project('Substance')
