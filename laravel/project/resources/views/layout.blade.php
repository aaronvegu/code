<!DOCTYPE HTML>
<!--
    Theory by TEMPLATED
    templated.co @templatedco
    Released for free under the Creative Commons Attribution 3.0 license (templated.co/license)
-->
<html>
    <head>
        <title>Theory by TEMPLATED</title>
        <meta charset="utf-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1" />
        <link rel="stylesheet" href="/assets/css/main.css" />
    </head>
    
    @yield ('bodyTag')

        <!-- Header -->
            <header id="header">
                <div class="inner">
                    <a href="/" class="logo">Theory</a>
                    <nav id="nav">
                        <a href="/">Home</a>
                        <a href="/articles">Articles</a>
                        <a href="/elements">Elements</a>
                    </nav>
                    <a href="#navPanel" class="navPanelToggle"><span class="fa fa-bars"></span></a>
                </div>
            </header>

            @yield ('main')

            <!-- Footer -->
            <footer id="footer">
                <div class="inner">
                    <div class="flex">
                        <div class="copyright">
                            &copy; Untitled. Design: <a href="https://templated.co">TEMPLATED</a>. Images: <a href="https://unsplash.com">Unsplash</a>.
                        </div>
                        <ul class="icons">
                            <li><a href="#" class="icon fa-facebook"><span class="label">Facebook</span></a></li>
                            <li><a href="#" class="icon fa-twitter"><span class="label">Twitter</span></a></li>
                            <li><a href="#" class="icon fa-linkedin"><span class="label">linkedIn</span></a></li>
                            <li><a href="#" class="icon fa-pinterest-p"><span class="label">Pinterest</span></a></li>
                            <li><a href="#" class="icon fa-vimeo"><span class="label">Vimeo</span></a></li>
                        </ul>
                    </div>
                </div>
            </footer>

        <!-- Scripts -->
            <script src="assets/js/jquery.min.js"></script>
            <script src="assets/js/skel.min.js"></script>
            <script src="assets/js/util.js"></script>
            <script src="assets/js/main.js"></script>

    </body>
</html>
