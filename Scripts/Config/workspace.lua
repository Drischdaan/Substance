workspace(project_name)
	location(root_path)

	configurations({
		build_configurations.Debug,
		build_configurations.Development,
		build_configurations.Shipping,
	})

	platforms({
		build_platforms.Windows,
	})

	defaultplatform(build_platforms.Windows)

	rw_filter_windows()
		system('windows')
		architecture('x86_64')
	rw_filter_end()

	defines({
		macro_prefix .. 'PROJECT_NAME="' .. project_name .. '"',
		macro_prefix .. 'PROJECT_VERSION="' .. project_version .. '"',
		macro_prefix .. 'PROJECT_VERSION_MAJOR=' .. project_version_major,
		macro_prefix .. 'PROJECT_VERSION_MINOR=' .. project_version_minor,
		macro_prefix .. 'PROJECT_VERSION_PATCH=' .. project_version_patch,
		macro_prefix .. 'PROJECT_VERSION_SUFFIX="' .. project_version_suffix .. '"',
		macro_prefix .. 'PROJECT_FULL_VERSION="' .. project_version_string .. '"',
		macro_prefix .. 'PROJECT_AUTHOR="' .. project_author .. '"',
	})

	rw_filter_configuration_debug()
		defines({
		})
	rw_filter_end()
	
	rw_filter_configuration_development()
		defines({
		})
	rw_filter_end()
	
	rw_filter_configuration_shipping()
		defines({
		})
	rw_filter_end()
