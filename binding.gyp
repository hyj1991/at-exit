{
  "targets": [
    {
      "target_name": "atExit",
      "sources": [
        "src/addon.cc",
        "src/exit.cc"
      ],
      "include_dirs" : [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}