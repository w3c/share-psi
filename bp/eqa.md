# Best Practice: Enable Quality Assessment of Open Data

## Outline
Data Quality DQ is primarily perceived to be a subjective term: What suffices, is “good enough” for one person, might be inferior to another. “Suffice” here means to be suitable to fulfil a certain need in a process. However beside the subjective aspect of DQ, there is an objective view on DQ which can be measured and help to establish provable and comprehensible metrics on DQ. The adherence to standards, enforced by tools which in turn are embedded in and used by processes, will help to raise DQ. In order to sustainably raise DQ, measures need to be in place all along the data pipeline and not only at the providing front end. DQ improvement has to be considered as a process rather than a one-time measure.

## Links to the Revised PSI Directive
[Quality](https://www.w3.org/2013/share-psi/bp/quality/)

## Challenge
The proliferation of open data as a mean to foster open innovation processes towards improved or new products and services, to increase transparency and to perform self-empowered impact measurement of policies also raises concerns about the quality of the provided resources. The early assumption that more data, even of uncertain origin and quality, will unconditionally result in better decisions as long as the right algorithms are used, gave again way to the insight that the principle of garbage-in, garbage-out still holds true. This fact combined with raising concerns regarding data platform usability, data literacy and trust put the quality aspect into the focus. Ironically government Data Quality became of an issue lately primarily due to the fact that government started to release data sets as Open Data which enables stakeholders to carry out citizens control rights. Bringing together data from diverse sources for the first time partially makes data issues like missing data obvious, but even more so deficiencies which arouse due to lacking or missing Master Data Management.

## Solution
 Traditional metrics to assess Data Quality like accuracy, applicability, and understandability remain relevant, and in the realm of Open Data, get extended by measures like openness, timeliness and primacy.  Work carried out in the European Commission's [Open Data Support](https://joinup.ec.europa.eu/sites/default/files/d2.1.2_training_module_2.2_open_data_quality_v1.00_en.pdf) project suggests seven aspects to consider:

 * Accuracy: is the data correctly representing the real-world entity or event?
 * Consistency: Is the data not containing contradictions?
 * Availability: Can the data be accessed now and over time?
 * Completeness: Does the data include all data items representing the entity or event?
 * Conformance: Is the data following accepted standards?
 * Credibility: Is the data based on trustworthy sources?
 * Processability: Is the data machine-readable?
 * Relevance: Does the data include an appropriate amount of  data?
 * Timeliness: Is the data representing the actual situation and is it published soon enough?

DQ improvement measures have to be in place all along the [(open) data life cycle](https://www.w3.org/2013/share-psi/workshop/lisbon/OpenDataLifeCycleBarCamp), otherwise quality measures will be perceived to be an additional burden, causing efforts and costing money. Also note, that the Open Data Life Cycle is - a cycle which suggest to set up data improvement measures as a process rather than a one time measure.

## Why is this a best practice?
Lacking DQ will reduce data users trust and prevent the unfolding of an open data market. Investment into DQ will pay back internally to the administration, as the potential for interoperable  data services will be risen as well as externally, as for data users it will become more easy to blend together data sets of diverse sources to create added value services.

## How to implement this Best Practice?
Implementation of this BP requires addressing the problem from a technical as well as organisational perspective.

**Technically**, DQ can be risen by adhering to conventions, norms and standards. However, the adoption of conventions, norms and standards requires governance at various levels. Set-up of governance structures is typically in the responsibility of the CIO or someone in charge with comparable powers and duties.

* It's within the CIOs responsibility to provide guidance on how to structure and implement ICT-systems, which use common and agreed conventions, norms and standards.
* The CIO should be responsible to identify semantically equivalent data entities, describe standards according to which these data entities should be modeled and monitor the adherence to these standards.

Common data entities, where possible, should be modeled according to the [core vocabuilaries](https://joinup.ec.europa.eu/asset/core_vocabularies/description).

CSV files could be annotated using W3Cs [CSV on the web](https://www.w3.org/2013/csvw/wiki/Main_Page) recommendations, which also included a formalized model to describe the columns of CSV files.

Data descriptions should be made according to the [DCAT-AP](https://joinup.ec.europa.eu/asset/dcat_application_profile/description) vocabulary.

During the data publishing stage, the W3C proposed Data Quality Vocabulary [DQV](https://www.w3.org/TR/vocab-dqv/) can be used to provides a framework in which the quality of a dataset can be described either by the publisher or the wider audience.

Tools can automatically check a certain range of DQ domains, like [adherence to claimed encodings](https://en.wikipedia.org/wiki/File_(command)#Libmagic_library) (utf8) or [structural regularity of CSV](http://csvlint.io/) files.

For assessing the quality of the dataset itself prior to publishing, e.g. for publishing statistical data in RDF format an [RDF Data Cube validator](http://svn.aksw.org/projects/GeoKnow/Public/D4.6.1_Quality_assessment_services_for_ESTA-LD.pdf) (PDF) can be used.

To enrich the data with quality assessment information and track provenance in RDF integration process, e.g. the [UnifiedViews](http://unifiedviews.eu/) tool can be used.


**Organisation-wise**
* the CIO should implement a data governance framework which comprises data architecture management, meta-data management, and master data management MDM.
* The importance of data as a mission-critical asset can be risen by establishing the role of the Chief Data Office CDO.
* Principles of ISO 8000, like Vocabulary usage, semantic encoding, Provenance, Accuracy and Completeness can be taken into account.

The [obligatory usage](https://www.gov.uk/government/publications/open-standards-for-government/cross-platform-character-encoding-profile) of minimum widespread technical standards like utf8 could be enforced by legal measures or order of the federal CIO.

To assess the publishing process, consider the steps described by [ODI Certificates](https://certificates.theodi.org/) (or similar).

## Further reading
Data Quality Vocabulary [DQV](https://www.w3.org/TR/vocab-dqv/)  
Introduction to [ISO 8000](http://www.itds.gov/linkhandler/itds/tsn/product_info_comm/iso_standard.ctt/iso_standard.pdf)  
[Data Management Body of Knowledge DMBoK ](https://www.dama.org/content/body-knowledge)  
Standards on [eProcurement](https://www.cen.eu/work/areas/ICT/eBusiness/Pages/default.aspx)  
Standards on [eInvoicing](http://ec.europa.eu/DocsRoom/documents/10472/attachments/1/translations/en/renditions/native)

##  Where has this best practice been implemented?

| Country | Initiative | Contact Point |
|---|---|---:|
| Austria | Mission Statement of the Sub-working Group [Quality Assurance of Open Data Portals](https://docs.google.com/document/d/1HUXuAKd4KO8NgZFiuMJWl0zXQ_NFPTF03t7esJVin-0/edit) of the Cooperation Open Government Data Austria | [Cooperation OGD Austria](https://www.data.gv.at/infos/cooperation-ogd-oesterreich/) |
| United Kingdom | [Cross platform character encoding profile](https://www.gov.uk/government/publications/open-standards-for-government/cross-platform-character-encoding-profile) | ??? |
| United Kingdom | [ODI Certificate for the Westminster City Council](https://certificates.theodi.org/en/datasets/5122/certificate) | Westminster City Council |
| Serbia | [Validating RDF Data Cube Models](http://www.linkeddata.rs/sites/default/files/attachments/LOD2_Tool_RDF_DataCube%20_Validation_for_submission_final.pdf) |Valentina Janev, Mihailo Pupin Institute, University of Belgrade, Belgrade, Serbia |
| Finland | [Valmistele ja avaa - Prepare and open](https://www.avoindata.fi/fi/opas/valmistele) Section 3.6. Tiedon viimeistely ja laatu - Finishing the data and data quality|Prime Ministers Office Finland |

# References
* David Corsar, Peter Edwards, [Enhancing Open Data with Provenance](http://www.dotrural.ac.uk/digitalfutures/sites/default/files/digitalfutures2012papers/Papers/Session2COpenData/Corsar%26Edwards_OpenData%26Provenance.pdf), dot.rural Digital Economy Hub
* [ProvenanceWeek 2014](http://provenanceweek.dlr.de/ipaw/)
* Giorgos Flouris, Yannis Roussakis, Marrıa Poveda-Villalon, Pablo N. Mendes, Irini Fundulaki, [Using Provenance for Quality Assessment and Repair in Linked Open Data](http://www.planet-data.eu/sites/default/files/publications/EvoDyn12.pdf), 2nd Joint Workshop on Knowledge Evolution and Ontology Dynamics (EvoDyn-12) at the ISWC2012
* Makx Dekkers, AMI Consult, [How good is good enough?](https://www.w3.org/2013/share-psi/wiki/images/3/3e/AMI_proposal_Share-PSI_Timisoara_How_good_is_good_enough.pdf)
* Amanda Smith & Sumika Sakanishi, ODI, [Publishing and improving the quality of open data with Open Data Certificates](https://www.w3.org/2013/share-psi/workshop/krems/papers/OpenDataCertificates), United Kingdom
* https://www.w3.org/2013/share-psi/wiki/Samos/Scribe#Speaker_notes
* https://www.w3.org/2013/share-psi/wiki/Lisbon/Scribe#Roadblocks_in_Commercial_Open_Data_Usage
* https://www.w3.org/2013/share-psi/wiki/Timisoara/Scribe#How_good_is_good_enough.3F_A_common_language_for_quality.3F  

# Contact Info
Original Author(s): Johann Höchtl <johann.hoechtl@donau-uni.ac.at>, Valentina Janev <valentina.janev@institutepupin.com>

Contributors: Muriel Foulonneau <muriel.foulonneau@list.lu>,
Lorenzo Canova <lorenzo.cnv@gmail.com>

Editors: Valentina Janev, Johann Höchtl
