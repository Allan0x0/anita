<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="2.0"
                xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
                xmlns:outline="http://wkhtmltopdf.org/outline"
                xmlns="http://www.w3.org/1999/xhtml">
  <xsl:output doctype-public="-//W3C//DTD XHTML 1.0 Strict//EN"
              doctype-system="http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd"
              indent="yes" />
  <xsl:template match="outline:outline">
    <html>
      <head>
        <title>Table of Contents</title>
        <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
        <style>
          /* Match the book's Site Journal look. Page margins are 0 in build.sh,
             so this page paints its own timber ground and insets with padding. */
          html, body { margin: 0; padding: 0; }
          body {
            background: #F3EDE1;
            color: #22201B;
            font-family: Georgia, "Iowan Old Style", "Times New Roman", serif;
            padding: 6mm 16mm 12mm;
          }
          h1 {
            text-align: center;
            font-size: 30pt;
            font-weight: 700;
            margin: 0 0 8mm;
            letter-spacing: -.01em;
          }
          ul { list-style: none; padding-left: 0; margin: 0; }
          li { list-style: none; }
          /* one entry row: dashed leader, page number floated right, breathing room */
          div {
            border-bottom: 1px dashed #C9BFA6;
            padding: 6px 0;
            font-size: 18pt;
            line-height: 1.3;
          }
          a { text-decoration: none; color: #22201B; }
          span { float: right; padding-left: 8px; font-variant-numeric: tabular-nums; }
          /* top-level entries are chapters: a touch bigger, blueprint blue */
          body > ul > li > div { font-size: 20pt; }
          body > ul > li > div a { color: #1D5A80; font-weight: 700; }
          /* nested (sub-section) entries: indented, smaller, muted */
          ul ul { padding-left: 10mm; }
          ul ul div { font-size: 16pt; color: #4A463D; }
          ul ul div a { color: #4A463D; }
        </style>
      </head>
      <body>
        <h1>Contents</h1>
        <ul><xsl:apply-templates select="outline:item/outline:item"/></ul>
      </body>
    </html>
  </xsl:template>
  <xsl:template match="outline:item">
    <li>
      <xsl:if test="@title!=''">
        <div>
          <a>
            <xsl:if test="@link">
              <xsl:attribute name="href"><xsl:value-of select="@link"/></xsl:attribute>
            </xsl:if>
            <xsl:if test="@backLink">
              <xsl:attribute name="name"><xsl:value-of select="@backLink"/></xsl:attribute>
            </xsl:if>
            <xsl:value-of select="@title" /> 
          </a>
          <span> <xsl:value-of select="@page" /> </span>
        </div>
      </xsl:if>
      <ul>
        <xsl:comment>added to prevent self-closing tags in QtXmlPatterns</xsl:comment>
        <xsl:apply-templates select="outline:item"/>
      </ul>
    </li>
  </xsl:template>
</xsl:stylesheet>
