################################################################################

# Created: 15th June 2004
# Updated: 16th January 2005

################################################################################

require "mkmf"
require "ftools"

def pr_err(e)
	print e + "\n"
	abort
end

#if !ENV.has_key?("OPENRJ_DEV")
#	pr_err("OPENRJ_DEV environment variable not defined")
#end

dir_config("openrj")


case RUBY_PLATFORM
when /mswin32/
	# Note that the following line is a direction for the make system to include 'openrj.vc6.dll.lib', not 'openrj.vc6.dll' !!
	$libs = append_library($libs, "openrj.vc6.dll")
	$libs = append_library($libs, "wininet")
else
	$libs = append_library($libs, "openrj")
end


create_makefile("openrj")

################################################################################
