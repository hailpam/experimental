#include <http_scraper.h>


HttpScraper::HttpScraper(): isDebug(false), provider("www.timeanddate.com"),
                            city("London"), host("178.79.200.143"),
                            url("http://www.timeanddate.com/worldclock/city.html?n=1440"),
                            startTag("<strong id=ct  class=big>"), endTag("</strong>"),
                            port(80)
{
}

HttpScraper::HttpScraper(bool isDebug): provider("www.timeanddate.com"), city("London"),
                                        host("178.79.200.143"),
                                        url("http://www.timeanddate.com/worldclock/city.html?n=1440"),
                                        startTag("<strong id=ct  class=big>"), endTag("</strong>"),
                                        port(80)
{
    this->isDebug = isDebug;
}

HttpScraper::~HttpScraper()
{
    /* nothing to do, no dynamic extension */
}

string HttpScraper::scrapeTime(const string& cityName) throw ()
{
    throw "Not yet implemented";
}

string HttpScraper::scrapeUtcTime() throw ()
{
    string htmlContent = this->getHtml();
    string utc = "";
    stringstream scraped;
    unsigned int length = htmlContent.length();
    size_t found = htmlContent.find("Universal Coordinated Time");
        if (found != string::npos) {
            if(this->isDebug)
                std::cout << "[HttpScraper][scrapeUtcTime] found at [" << found << "] of [" << length << "]" << endl;
            bool tagging = false;
            unsigned int tagIdx = 0;
            const char* tag = this->startTag.c_str();
            bool sampling = false;
            bool finalising = false;
            unsigned int finIdx = 0;
            const char* fin = this->endTag.c_str();
            const char* rawContent = htmlContent.c_str();
            for(unsigned int i = found; i < htmlContent.size(); i++) {
                //cout << rawContent[i] << endl;
                if(tagging) {
                    if(rawContent[i] == tag[tagIdx]) {
                        if(this->isDebug)
                            cout << rawContent[i];
                        if(tagIdx == (this->startTag.size() - 1)) {
                            tagIdx = 0;
                            sampling = true;
                            tagging = false;
                        }else
                            tagIdx += 1;
                    }else {
                        tagging = false;
                        tagIdx = 0;
                        if(this->isDebug)
                            cout << endl << "tagging ended: " << rawContent[i] << endl;
                    }
                }else if(sampling) {
                    scraped << rawContent[i];
                    if(rawContent[i] == fin[finIdx]) {
                        if(finalising) {
                            if(this->isDebug)
                                cout << rawContent[i];
                            if(finIdx == (this->endTag.size() - 1)) {
                                utc = scraped.str().substr(0, (scraped.str().size() - 9));
                                if(this->isDebug)
                                    cout << endl << "scraped: { " << utc << " }" << endl;
                                break;
                            }
                            finIdx += 1;
                        }else {
                            finalising = true;
                            finIdx += 1;
                            if(this->isDebug)
                                cout << endl << "finalising " << rawContent[i];
                        }
                    }else if(finalising) {
                        finalising = false;
                        finIdx = 0;
                        if(this->isDebug)
                            cout << endl << "finalising ended: " << rawContent[i] << endl;
                    }
                }else if(rawContent[i] == tag[tagIdx]) {
                    tagging = true;
                    if(this->isDebug)
                        cout << "tagging " << rawContent[i];
                    tagIdx += 1;
                }
            }
    }else {
        cerr << "[HttpScraper][scrapeUtcTime] error: unable to find UTC data in the HTML string" << endl;
        utc = "N/A";
    }

    return utc;
}

string HttpScraper::getHtml() throw ()
{
    int sockFd, error;
    struct sockaddr_in addr;
    stringstream content;

    if((sockFd = socket(AF_INET,SOCK_STREAM,0)) < 0) {
        cerr <<"[HttpScraper][getHtml] error: connection socket failed!\n";

        throw "[HttpScraper][getHtml] error: connection socket failed!\n";
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(this->port);
    inet_aton(this->host.c_str(),&addr.sin_addr);

    error = connect(sockFd,(sockaddr*)&addr,sizeof(addr));
    if(error != 0) {
        cerr <<"[HttpScraper][getHtml] error: connection to server failed!\n";

        throw "[HttpScraper][getHtml] error: connection to server failed!\n";
    }

    char message[] = "GET http://www.timeanddate.com/worldclock/city.html?n=1440 http/1.0\nHOST: www.timeanddate.com\n\n";
    // TODO : issue with .c_str()
    //string message = "GET " +this->url +" http/1.0\nHOST: " +this->provider +"\n\n";
    if(this->isDebug)
        cout << "[HttpScraper][getHtml] HTTP Request >> {" << endl << message << endl << " }" << endl;
    char serverRes[16384];

    send(sockFd, message, sizeof(message), 0);

    while(recv(sockFd, serverRes, 16384, 0) != 0)
        content << serverRes;

    if(this->isDebug)
        cout << "[HttpScraper][getHtml] content {" << content.str() << "}" << endl;

    return content.str();
}

void HttpScraper::setProvider(const string& provider)
{
    this->provider = provider;
}

void HttpScraper::setCity(const string& city)
{
    this->city = city;
}

void HttpScraper::setHost(const string& host)
{
    this->host = host;
}

void HttpScraper::setUrl(const string& url)
{
    this->url = url;
}

void HttpScraper::setStartTag(const string& startTag)
{
    this->startTag = startTag;
}

void HttpScraper::setEndTag(const string& endTag)
{
    this->endTag = endTag;
}

void HttpScraper::setPort(const int& port)
{
    this->port = port;
}

const string& HttpScraper::getProvider() const
{
    return this->provider;
}

const string& HttpScraper::getCity() const
{
    return this->city;
}

const string& HttpScraper::getHost() const
{
    return this->host;
}

const string& HttpScraper::getUrl() const
{
    return this->url;
}
const string& HttpScraper::getStartTag() const
{
    return this->startTag;
}

const string& HttpScraper::getEndTag() const
{
    return this->endTag;
}

const int& HttpScraper::getPort() const
{
    return this->port;
}
