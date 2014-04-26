#include <iostream>

#include <http_scraper.h>

int main (int argc, char* argv[]) {
    string provider;
    cout << "[main] scraping UTC time" << endl;
    HttpScraper* scraper = new HttpScraper(false);
    cout << "[main] provider " << scraper->getProvider() << endl;
    string utc = scraper->scrapeUtcTime();
    cout << "[main] scraped { " << utc << " }" << endl;

    return 0;
}
