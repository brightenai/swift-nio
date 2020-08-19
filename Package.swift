// swift-tools-version:5.2
//===----------------------------------------------------------------------===//
//
// This source file is part of the SwiftNIO open source project
//
// Copyright (c) 2017-2018 Apple Inc. and the SwiftNIO project authors
// Licensed under Apache License v2.0
//
// See LICENSE.txt for license information
// See CONTRIBUTORS.txt for the list of SwiftNIO project authors
//
// SPDX-License-Identifier: Apache-2.0
//
//===----------------------------------------------------------------------===//

import PackageDescription

var targets: [PackageDescription.Target] = [
//    .target(name: "_NIO1APIShims",
//            dependencies: ["NIO", "NIOHTTP1", "NIOTLS", "NIOFoundationCompat", "NIOWebSocket"]),
    .target(name: "NIO",
            dependencies: ["CNIOLinux",
                           "CNIODarwin",
                           "NIOConcurrencyHelpers",
                           "CNIOAtomics",
                           "CNIOSHA1"]
            linkerSettings: [
                            .unsafeFlags([ "-Xlinker","-soname=libNIO.so"],.when(platforms: [.android])),
                             ]
),
    .target(name: "NIOFoundationCompat", dependencies: ["NIO"]
//            linkerSettings: [
//                            .unsafeFlags([ "-Xlinker","-soname=libNIOFoundationCompat.so"],.when(platforms: [.android])),
//                             ]
    ),
    .target(name: "CNIOAtomics", dependencies: []),
    .target(name: "CNIOSHA1", dependencies: []),
    .target(name: "CNIOLinux", dependencies: []),
    .target(name: "CNIODarwin", dependencies: []),
    .target(name: "NIOConcurrencyHelpers",
            dependencies: ["CNIOAtomics"],
            linkerSettings: [
                            .unsafeFlags([ "-Xlinker","-soname=libNIOConcurrencyHelpers.so"],.when(platforms: [.android])),
                             ]
    ),
    .target(name: "NIOHTTP1",
            dependencies: ["NIO", "NIOConcurrencyHelpers", "CNIOHTTPParser"]
//            linkerSettings: [
//                            .unsafeFlags([ "-Xlinker","-soname=libNIOHTTP1.so"],.when(platforms: [.android])),
//                             ]
    ),
    .target(name: "NIOEchoServer",
            dependencies: ["NIO", "NIOConcurrencyHelpers"]),
    .target(name: "NIOEchoClient",
            dependencies: ["NIO", "NIOConcurrencyHelpers"]),
    .target(name: "NIOHTTP1Server",
            dependencies: ["NIO", "NIOHTTP1", "NIOConcurrencyHelpers"]),
    .target(name: "NIOHTTP1Client",
            dependencies: ["NIO", "NIOHTTP1", "NIOConcurrencyHelpers"]),
    .target(name: "CNIOHTTPParser"),
    .target(name: "NIOTLS", dependencies: ["NIO"]
//            linkerSettings: [
//                            .unsafeFlags([ "-Xlinker","-soname=libNIOTLS.so"],.when(platforms: [.android])),
//                             ]
    ),
    .target(name: "NIOChatServer",
            dependencies: ["NIO", "NIOConcurrencyHelpers"]),
    .target(name: "NIOChatClient",
            dependencies: ["NIO", "NIOConcurrencyHelpers"]),
    .target(name: "NIOWebSocket",
            dependencies: ["NIO", "NIOHTTP1", "CNIOSHA1"]),
    .target(name: "NIOWebSocketServer",
            dependencies: ["NIO", "NIOHTTP1", "NIOWebSocket"]),
    .target(name: "NIOWebSocketClient",
            dependencies: ["NIO", "NIOHTTP1", "NIOWebSocket"]),
    .target(name: "NIOPerformanceTester",
            dependencies: ["NIO", "NIOHTTP1", "NIOFoundationCompat", "NIOWebSocket"]),
    .target(name: "NIOMulticastChat",
            dependencies: ["NIO"]),
    .target(name: "NIOUDPEchoServer",
            dependencies: ["NIO"]),
    .target(name: "NIOUDPEchoClient",
            dependencies: ["NIO"]),
    .target(name: "NIOTestUtils",
            dependencies: ["NIO", "NIOHTTP1"]),
    .target(name: "NIOCrashTester",
            dependencies: ["NIO", "NIOHTTP1", "NIOWebSocket", "NIOFoundationCompat"]),
//    .testTarget(name: "NIOTests",
//                dependencies: ["NIO", "NIOFoundationCompat", "NIOTestUtils", "NIOConcurrencyHelpers"]),
//    .testTarget(name: "NIOConcurrencyHelpersTests",
//                dependencies: ["NIOConcurrencyHelpers", "NIO"]),
//    .testTarget(name: "NIOHTTP1Tests",
//                dependencies: ["NIOHTTP1", "NIOFoundationCompat", "NIOTestUtils"]),
//    .testTarget(name: "NIOTLSTests",
//                dependencies: ["NIO", "NIOTLS", "NIOFoundationCompat"]),
//    .testTarget(name: "NIOWebSocketTests",
//                dependencies: ["NIO", "NIOWebSocket"]),
//    .testTarget(name: "NIOTestUtilsTests",
//                dependencies: ["NIOTestUtils"]),
//    .testTarget(name: "NIOFoundationCompatTests",
//                dependencies: ["NIO", "NIOFoundationCompat"]),
]

let package = Package(
    name: "swift-nio",
    products: [
        
        .library(name: "CNIODarwin",type:.static,  targets: ["CNIODarwin"]),
        .library(name: "NIO",type:.dynamic,  targets: ["NIO"]),
//        .library(name: "_NIO1APIShims",type:.static, targets: ["_NIO1APIShims"]),
        .library(name: "NIOTLS",type:.static, targets: ["NIOTLS"]),
        .library(name: "NIOHTTP1",type:.static, targets: ["NIOHTTP1"]),
        .library(name: "NIOConcurrencyHelpers", type:.dynamic,targets: ["NIOConcurrencyHelpers"]),
        .library(name: "NIOFoundationCompat",type:.static, targets: ["NIOFoundationCompat"]),
        .library(name: "NIOWebSocket",type:.static, targets: ["NIOWebSocket"]),
        .library(name: "NIOTestUtils",type:.static, targets: ["NIOTestUtils"]),
    ],
    dependencies: [
    ],
    targets: targets
)
