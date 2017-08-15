if (typeof(SiteBot) === 'undefined') {
    var SiteBot = {
        isTrackExisted:false
    };
};
(function(){
    if (SiteBot.isTrackExisted) {
        return;
    };
    SiteBot.isTrackExisted = true;
    /* if no referrer existed, don't do anything */
   var from_sitebot = '';
   var sitebot_cookie_name = 'sitebot_cookie_name' + sitebot_userid;
    if(document.referrer&&document.referrer!='')
    {
    	var regx=/^http[\w]?:\/\/(.*?)(sitebot|sitebro)\.([^/]+)/i;
	if(regx.test(document.referrer))
	{
  	    var exp = new Date();
	    exp.setTime(exp.getTime() + 360*24*60*60*1000);
	    document.cookie = sitebot_cookie_name + ' =' + escape(document.referrer) + ';expires=' + exp.toGMTString();
	}
    }

    var arr,reg=new RegExp("(^| )"+sitebot_cookie_name+"=([^;]*)(;|$)");
    if(arr=document.cookie.match(reg))
    {
    	var referrer = encodeURIComponent(unescape(arr[2]));
    }
    else
    {
    	var referrer = (document.referrer&&document.referrer!='')?encodeURIComponent(document.referrer):'';
    }

    if(referrer == ''){
        return;
    };
    from_sitebot = referrer;
    /* if referrer has the same hostname with the location.hostname */
    var sTarget = 'track.php';
    /* grab client information */
    var oData = {
        'agent':encodeURIComponent(navigator.userAgent.toLowerCase()),
        'version':encodeURIComponent(navigator.appVersion.toLowerCase()),
        'cpu':(navigator.cpuClass)?encodeURIComponent(navigator.cpuClass):encodeURIComponent(navigator.oscpu),
        'platform':encodeURIComponent(navigator.platform),
        'language':sitebot_lang,
        'appname':encodeURIComponent(navigator.appName),
        'timezone':(new Date()).getTimezoneOffset()*(-1),
        'resolution':[screen.width,screen.height],
        'colordepth':screen.colorDepth,
        'title':encodeURIComponent(document.title),
        'location':encodeURIComponent(document.location),
        'referrer':(document.referrer&&document.referrer!='')?encodeURIComponent(document.referrer):'',
        'product':(navigator.product!==undefined)?encodeURIComponent(navigator.product):'',
        'productsub':(navigator.productSub!==undefined)?encodeURIComponent(navigator.product):'',
        'vendor':(navigator.vendor!==undefined)?encodeURIComponent(navigator.vendor):'',
        'vendorsub':(navigator.vendorSub!==undefined)?encodeURIComponent(navigator.vendorSub):'',
        'userid':sitebot_userid,
        'websiteid':sitebot_websiteid,
        'from_sitebot':from_sitebot
    };
    aData = [];
    for(var i in oData){
        aData[aData.length] = i + '=' + oData[i]
    };
    sitebot_JsHost = sitebot_JsHost.replace(/\btrack\b/g, 'tracking');
    var sRequestUrl = sitebot_JsHost + sTarget + '?url=' + encodeURIComponent(location.href) + '&' + aData.join('&');
    var objImage = new Image(1,1);
    objImage.src = sRequestUrl;
    /*
    var dScript = document.createElement('script');
    dScript.setAttribute('src',sRequestUrl);
    dScript.setAttribute('type','text/javascript');
    if(document.uniqueID && document.expando){
        window.attachEvent('onload',function(){
            document.body.appendChild(dScript);
        });
    }
    else {
        window.addEventListener('load',function(){
            document.body.appendChild(dScript);
        },false);
    };
    */
}());
/*
(function(){
	/*show tips
	var dtips = document.getElementById('sitebro_stick_logo'),timer = null;
	if(!dtips){return;}
	var getPosition = function(o){var x=0,y=0;do{x+=o.offsetLeft;y+=o.offsetTop;}while((o=o.offsetParent));return{'x':x,'y':y};};
	var surl = sitebot_JsHost.replace(/(http:\/\/)[^\.]*\.(.*)/i,'$1$2');
	var targeturl = surl + '/stick.html?wid='+sitebot_websiteid+'&lang='+sitebot_lang;
	var sitebot_name = sitebot_lang == 'zh_CN' ? 'Sitebot' : 'Sitebro';
	var stips = '<iframe id="sitebot_stick_popup" src="about:blank" frameborder="0" scrolling="no" allowtransparency="allowtransparency" style="position:absolute;left:0;top:0;z-index:100000;width:500px;height:310px;background:transparent;display:none;"></iframe>';
	document.write(stips);
	var difr = document.getElementById('sitebot_stick_popup'),dinnerFrame = null,bshowed = false;
	var showiframe = function(){if(bshowed||!dinnerFrame){return;}dinnerFrame.src=targeturl;};
	var hideSP = function(){difr.style.display = 'none';window.clearTimeout(timer);};
	var setifrsrc = function(){
		var dopen = difr.contentWindow.document.open();
		dopen.write('<!doctype html public "-//w3c//dtd html 4.01//en" "http://www.w3.org/tr/html4/strict.dtd"><html><head><meta http-equiv="Content-Type" content="text/html; charset=utf-8" /><title>Stick</title><base href="'+surl+'" /><link rel="stylesheet" type="text/css" href="/css/dystyle.css" /><link rel="stylesheet" type="text/css" href="/css/stick.css" /><style type="text/css">html,body{background:transparent;padding:0 20px;}#wgstick .stick .bd{overflow:hidden;}</style></head><body><div id="wgstick"><div class="stick"><div class="hd"></div><div class="bd"><iframe frameborder="0" src="about:blank"></iframe></div><div class="ft"><a href="'+surl+'" class="copyico" title="'+sitebot_name+'" target="_blank">'+sitebot_name+'</a></div></div></div></body></html>');
		dopen.close();
		dinnerFrame = difr.contentWindow.document.getElementsByTagName('iframe')[0];
		difr.onmousemove = function(){window.clearTimeout(timer);};
		difr.contentWindow.onmousemove = function(){window.clearTimeout(timer);};
		difr.contentWindow.document.onmousemove = function(){window.clearTimeout(timer);};
		difr.onmouseout = function(){timer = window.setTimeout(hideSP,1000);};
		dtips.onmouseover = function(){
			window.clearTimeout(timer);
			var pos = getPosition(this),x = pos.x-40,y = pos.y-310;
			difr.style.left = x+'px';
			difr.style.top = y+'px';
			showiframe();
			difr.style.display = 'block';
		};
		dtips.onmouseout = function(){timer = window.setTimeout(hideSP,1000);};
	};
	window.setTimeout(setifrsrc,1000);
	if(document.attachEvent){document.body.attachEvent('onclick',hideSP);}else{document.body.addEventListener('click',hideSP,false);}
})();
*/
