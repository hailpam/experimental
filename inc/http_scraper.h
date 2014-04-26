/**
 * @file http_scaper.h
 *
 * HTTP Scraper. It uses HTTP protocol to scrape HTML pages.
 *
 * @brief
 *
 * @author Paolo Maresca <plo.maresca@gmail.com>
 * @version 0.1
 */
// $Log$

#ifndef _HTTP_SCRAPER_H
#define _HTTP_SCRAPER_H

#include <string.h>
#include <iostream>
#include <sys/socket.h>
#include <resolv.h>
#include <arpa/inet.h>
#include <sstream>
#include <stdio.h>

using namespace std;

class HttpScraper
{
    public:
        /**
         * Default Constructor
         */
        HttpScraper();
        /**
         * Default Constructor
         *
         * @param   debug   True iff the module is in debug mode
         */
        HttpScraper(bool isDebug);
        /**
         * Default Destructor
         */
        ~HttpScraper();
        /**
         * Scrape current Time for the given city.
         *
         * @param   cityName    City of interest to scrape Time
         *
         * @return  A string wrapping the scraped time
         */
        string scrapeTime(const string& cityName) throw ();
        /**
         * Scrape current UTC Time for the given city.
         *
         * @return  A string wrapping the scraped time
         */
        string scrapeUtcTime() throw ();
        /**
         * Set the Provider.
         *
         * @param   Provider    A string representing the Provider
         */
        void setProvider(const string& provider);
        /**
         * Set the City.
         *
         * @param   City    A string representing the City
         */
        void setCity(const string& city);
        /**
         * Set the Host.
         *
         * @param   Host    A string representing the Host
         */
        void setHost(const string& host);
        /**
         * Set the URL.
         *
         * @param   URL    A string representing the URL
         */
        void setUrl(const string& url);
        /**
         * Set the Start Tag to scrape.
         *
         * @param   startTag    A string representing the starting Tag
         */
        void setStartTag(const string& startTag);
        /**
         * Set the Ent Tag that finalises the scraping.
         *
         * @param   entTag    A string representing the ending Tag
         */
        void setEndTag(const string& endTag);
        /**
         * Set the Port.
         *
         * @param   port    A string defining the TCP Port
         */
        void setPort(const int& port);
        /**
         * Get the Provider.
         *
         * @return  The service provider
         */
        const string& getProvider() const;
        /**
         * Get the City.
         *
         * @return  Time requesting City
         */
        const string& getCity() const;
        /**
         * Get the Host.
         *
         * @return  The service Host
         */
        const string& getHost() const;
        /**
         * Get the URL.
         *
         * @return  The service URL
         */
        const string& getUrl() const;
        /**
         * Get the start Tag to initialize the scraping.
         *
         * @return  The scraping start Tag
         */
        const string& getStartTag() const;
        /**
         * Get the end Tag to finalise the scraping.
         *
         * @return  The scraping end Tag
         */
        const string& getEndTag() const;
        /**
         * Get the service provider Port.
         *
         * @return  The service provider TCP Port
         */
        const int& getPort() const;

    protected:
        /**
         * Connect to the remote service and retrieve the HTML.
         *
         * @return  A string containing the HTML content of that page.
         */
        string getHtml() throw ();

    private:
        bool isDebug;
        string provider;
        string city;
        string host;
        string url;
        string startTag;
        string endTag;
        int port;
};

#endif      /* HTTP_SCRAPER_H */
