{
    "targets": [
        {
            "target_name": "addon",
            "sources": [
                "example.cc",
                "lib/lzokay/lzokay.cpp"
            ],
            "include_dirs" : [
                "<!(node -e \"require('nan')\")",
                "lib/lzokay/"
            ]
        }
    ]
}