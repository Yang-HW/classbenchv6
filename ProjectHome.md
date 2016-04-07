Recently, the significantly increased IPv6 address length has posed a greater challenge on wire-speed router for packet classification (PC). Most conventional IPv4-based PC algorithms are no longer suitable for IPv6 PC. The performance and capacity of many IPv6 algorithms and classification devices depend upon properties of the IPv6 classifiers. However, there are no publicly available IPv6 real classifiers due to the security and confidentiality reasons. Besides, since IPv6 implementation is still in the initial phase, IPv6 real classifiers at present are too small to depict the feature. Thus, researchers who work on IPv6 PC can only generate synthesized classifiers by ad hoc methods. In response to this problem, we present ClassBenchv6, a suite of tools for benchmarking IPv6 PC algorithms and devices. In this paper, we analyze the intrinsic relationship among the major characteristics of real classifiers and the associated IPv4/IPv6 RFC documents. Based on the analysis, we predict the high-level characteristics for IPv6 classifiers. Our ClassBenchv6 can generate different kinds of classifiers applied to different fields and be used to estimate newly proposed IPv6 PC algorithms comprehensively. It is simple, easy to configure and scalable for further IPv6 implementation. While we have already found ClassBenchv6 to be very useful in our own research, we seek to eliminate the significant access barriers to realistic test vectors and initiate a broader discussion to guide the refinement of the tools.