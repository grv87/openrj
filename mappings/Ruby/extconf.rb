################################################################################

# Created: 15th June 2004
# Updated: 16th August 2004

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
	$libs = append_library($libs, "openrj.vc6")
	$libs = append_library($libs, "wininet")
else
	$libs = append_library($libs, "openrj")
end


create_makefile("openrj")

################################################################################
