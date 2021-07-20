load("@rules_cc//cc:defs.bzl", "cc_library")

include_pattern = "boost/%s/"

hdrs_patterns = [
    "boost/%s.h",
    "boost/%s_fwd.h",
    "boost/%s.hpp",
    "boost/%s_fwd.hpp",
    "boost/%s/**/*.h",
    "boost/%s/**/*.hpp",
    "boost/%s/**/*.ipp",
    "libs/%s/src/*.ipp",
]

srcs_patterns = [
    "libs/%s/src/*.hpp",
    "libs/%s/src/*.cpp", 
]

# Building boost results in many warnings for unused values. 
# Downstream users won't be interested, so just disable the warning
default_cops = select({
    "@//third_party:linux": ["-Wno-unused-value"],
    "//conditions:default": [],
})

def srcs_list(library_name, exclude):
    return native.glob(
        [p % (library_name,) for p in srcs_patterns],
        exclude = exclude,
    )

def includes_list(library_name):
    return [".", include_pattern % library_name]

def hdrs_list(library_name):
    return native.glob([p % (library_name,) for p in hdrs_patterns])


def boost_library(
        name,
        defines = None,
        includes = None,
        hdrs = None,
        srcs = None,
        deps = None,
        copts = None,
        exclude_srcs = [],
        linkopts = None,
        visibility = ["//visibility:public"],
        linkstatic = False):
     if defines == None:
         defines = []
     if includes == None:
         includes = []
     if hdrs == None:
         hdrs = []
     if srcs == None:
         srcs = []
     if deps == None:
         deps = []
     if copts == None:
         copts = []
     if linkopts == None:
         linkotps = []

     return cc_library(
          name = name,
          visibility = visibility,
          defines = defines,
          includes = ["."] + includes,
          hdrs = hdrs_list(name) + hdrs,
          srcs = srcs_list(name, exclude_srcs) + srcs,
          deps = deps,
#          copts = default_copts + copts,
          copts = copts,
          linkopts = linkopts,
          licenses = ["notice"],
          linkstatic = linkstatic,
      )
    
