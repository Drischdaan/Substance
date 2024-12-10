rw_project('Substance')
	rw_default_location()
	rw_language_cpp()
	rw_kind_shared_lib('Substance')

	rw_default_files()
	rw_default_includes()
	rw_precompiled_header()

	defines({
		macro_prefix .. '_COMPILE_LIBRARY=1',
	})

	rw_copy_output_to_directory(path.join(project_build_output_path, 'Tests'))
