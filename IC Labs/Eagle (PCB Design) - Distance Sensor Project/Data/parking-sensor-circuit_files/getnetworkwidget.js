if(typeof(networkedblogs)=="undefined") {
	document.write("<span style='color:red'>NetworkedBlogs widget not installed correctly</span>");
}
else {
    // Constants
	if (typeof(networkedblogs.nwidget)=="undefined") {
		networkedblogs.nwidget = {};
	}
    networkedblogs.url = "http://networkedblogs.com/";
    networkedblogs.nwidget.url = "http://nwidget.networkedblogs.com/";

    // Functions
	networkedblogs.nwidget.popupFollow = function() {
	    window.open (networkedblogs.url + "followblog.php?name=" + networkedblogs.shortName,
	        "NetworkedBlogs", "status=1,toolbar=1,scrollbars=1,width=670,height=450");
	    return false;
	}

   	// This function calculates the fittable count of fans according to the given client area.
	networkedblogs.nwidget.getFanCount = function(w, h) {
		var xFanCount = Math.floor(w / (35 + 2 * 3)); // image + margin
		var yFanCount = Math.floor(h / (35 + 2 * 3)); // image + margin
		return xFanCount*yFanCount;
	};


    // Code starts here (embedded in a function to use local variables)
    (function() {
        var n = networkedblogs.nwidget;
        var container = document.getElementById("networkedblogs_nwidget_container");
        var widget = document.getElementById("networkedblogs_nwidget_widget");
        var body = document.getElementById("networkedblogs_nwidget_body");
        
        // Get width and height
        if (typeof(n.width) == "undefined"){
            n.width = container.clientWidth;
        }
        if (typeof(n.height) == "undefined"){
            n.height = container.clientHeight - container.style.paddingTop.replace("px", "");
        }
        widget.style.width = (n.width - 2) + "px";  // 2 = borders
        widget.style.height = n.height + "px";
        body.style.height = (n.height - 54) + "px";  // 54 = height of button + logo
        
        // Calculate how many followers we can fit.
        n.fanCount = n.getFanCount(n.width - 2 /* margins */, n.height - 54 /* logo + button */ - 10 /*buffer*/);

        // create iframe.
   	    n.iframe = document.createElement("iframe");
	    n.iframe.id = "networkedblogs_nwidget_iframe";
	    n.iframe.frameBorder = "0";
	    n.iframe.marginHeight = "0";
	    n.iframe.marginWidth = "0";
	    n.iframe.width = "100%";
	    n.iframe.height = "100%";
	    n.iframe.scrolling = "no";
	    if (typeof(n.fanCount) == "number")
		    n.iframe.src = n.url + "getnetworkwidgetmain?bid=" + networkedblogs.blogId.toString() +
		    "&fancount=" + n.fanCount.toString();
	    else
		    n.iframe.src = n.url + "getnetworkwidgetmain?bid=" + networkedblogs.blogId.toString()
	    body.appendChild(n.iframe);
	    document.getElementById("networkedblogs_nwidget_follow").getElementsByTagName("a")[0].onclick = n.popupFollow;
    })();
}