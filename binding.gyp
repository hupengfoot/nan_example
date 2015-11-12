{
    "targets": [
	{
	    "target_name": "addon",
	    "sources": [ "hello.cc", "async.cc", "binary.cc", "addon.cc" ],
	    "include_dirs" : [
		"<!(node -e \"require('nan')\")",
	    ],
	}
    ]
}
