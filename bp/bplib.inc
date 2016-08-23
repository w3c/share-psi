<?php

$base = "/2013/share-psi/bp/";
$w3Base = "/TR/dwbp/#";
// We're going to need that json file...
// copy file content into a string var
$json_file = file_get_contents('http://w3c.github.io/share-psi/bp/bps.json');
// convert the string to a json object
$jfo = json_decode($json_file);

// And the same for the implementations file
$implementations_file = file_get_contents('http://w3c.github.io/share-psi/bp/implementations.json');
// convert the string to a json object
$implementations = json_decode($implementations_file);
$impList = $implementations->imp;
$flagList = $implementations->groupFlags;

// Sort the BPs according to the sort order in the JSON file

$bpList = $jfo->BPs;
usort($bpList, "cmp");

function cmp($a, $b) {
  return strcmp($a->sortAs, $b->sortAs);
}

// Sort the localised guides by group

usort($impList, "cmpA");
function cmpA($a, $b) {
  return strcmp($a->group, $b->group);
}

// A function to list the 13 elements of the PSI Directive (defined in the BP file). May be rendered in an aside.
function elementsAside($aside=1) { 
  global $jfo;
  global $base;
  if ($aside == 1) {
    echo '<aside id="elementList"><h2>Elements of the (Revised) PSI Directive</h2>';
  }
  echo '<ul>';
  foreach ($jfo->elements as $e) {
     echo '<li><a href="'.$base.$e->id.'/">'.$e->title.'</a></li>';
  }
  echo "</ul>";
  if ($aside == 1) {
    echo "</aside>";
  }
}


// Main function to list all the BPs, grouped by PSI Directive element.
function listAllBPs() {
  global $jfo;
  global $base;
  global $w3Base;
  global $bpList;
  echo '<dl id="theList">';
  foreach ($jfo->elements as $e) {      // Main loop gthrough the elements
    echo '<dt id="'.$e->id.'">'.$e->title.' <span class="identifier"><a href="#'.$e->id.'">#'.$e->id.'</a></span></dt>';
    echo '<dd class="expansion">'.$e->sub.'</dd><dd class="bpList"><ul id="'.$e->id.'List">';
    foreach ($bpList as $b) {      // Looping through the BPs
      // Need to know which elements this BP refers to so we need...
      $relevant = $b->elements; // so $relevant is an array of elements to which $b is relevant
      foreach ($relevant as $r) {         // Now 3 loops deep
        if ($r == $e->id) {               // we have a match
          echo '<li class="';
          if ($b->src == 's') {
            echo 'share-psi"><a itemprop="hasPart" href="'.$base.$b->id.'/">';
          } else {
            echo 'w3c"><a itemprop="hasPart" href="'.$w3Base.$b->id.'">';
          }
//          echo '<span itemprop="name">'. $b->title.'</span></a></li>';
          echo $b->title.'</a></li>';
        }
      }
    }
    echo '</ul></dd>';
  }
  echo '</dl>';

}

// List all the BPs for a given element
function listElementsBPs($element) {
  global $jfo;
  global $base;
  global $w3Base;
  global $bpList;
  echo '<ul id="'.$element.'List">';
  foreach ($bpList as $b) {      // Looping through the BPs
    // Need to know which elements this BP refers to so we need...
    $relevant = $b->elements; // so $relevant is an array of elements to which $b is relevant
    foreach ($relevant as $r) {
      if ($r == $element) {               // we have a match
        echo '<li class="';
        if ($b->src == 's') {
          echo 'share-psi"><a href="'.$base.$b->id.'/">';
        } else {
          echo 'w3c"><a href="'.$w3Base.$b->id.'">';
        }
        echo $b->title.'</a></li>';
      }
    }
  }
  echo '</ul>';
}

// Just a function to get the BP JSON file into the page so we can access it from JavaScript without the need for an XHR request
function getJSONfile() {
  global $json_file;
  echo '<script type="text/javascript">var bpJSON = '.$json_file.'</script>';
}

function  listTerritories() {			// Writes links to the territories (groups) for which we have guides
  global $impList;
  global $flagList;
  foreach ($impList as $i) {
    if (isset($i->group)) {						# Avoid empty entries
      $group = $i->group;
      if (isset($sections[$group]) == false) {  # Haven't done this group before
        $sections[$group] = '<div class="countryLinks" id="guidesFor'.$group.'">';
        foreach ($flagList as $f) {
          if ($f->id == $group) {
            $sections[$group] .= '<a href="'.$group.'/"><img src="https://www.w3.org/2013/share-psi/bp/'.$f->flag.'" alt="flag of '.$group.'" class="countryLinkFlag" /></a>';
          }
        }
        $sections[$group] .= '<h2><a href="'.$group.'/">'.$group.'</a></h2><ul>';
      }
      if (strpos($i->lang, 'en')) {				# Deal with multilingual titles
        $sections[$i->group] .= '<li class="lgTitle" id="'.$i->id.'">'.$i->title.'</li>';
      } else {
        $sections[$i->group] .= '<li  class="lgTitle" id="'.$i->id.'" lang="'.$i->lang.'">'.$i->title.' <span class="translation">'.$i->titleEN.'</span></li>';
      }
    }
  }
  foreach ($sections as $s) {
    echo $s.'</ul></div>';
  }
}

// For a given group, list the guides.

function listImplementations($group) {
  global $impList;
  foreach ($impList as $i) {
    if (($i->title) && ($i->group == $group)) {						# Avoid empty entries and select by territory
      if ($i->flag) {
        echo '<img src="/2013/share-psi/bp/'.$i->flag.'" alt="flag of '.$i->spatial.'" class="lgFlag" />';
      }
      echo '<dl>';
      if (strpos($i->lang, 'en')) {				# Deal with multilingual titles
        echo '<dt class="lgTitle" id="'.$i->id.'">'.$i->title.'</dt>';
      } else {
        echo '<dt  class="lgTitle" id="'.$i->id.'" lang="'.$i->lang.'">'.$i->title.'</dt>';
        echo '<dd class="translation">'.$i->titleEN.'</dd>';
      }
      # Now going to work through lang spatial homepage landingpage downloadURL format issued creator
      if ($i->lang) {
        echo '<dd class="language">Language: '. strtoupper($i->lang).'</dd>';
      }
      
      if ($i->spatial) {
        echo '<dd class="spatial">Applies to: '.$i->spatial.'</dd>';
      }

      echo '<dd class="access">Access: ';

      if ($i->homepage) {
        echo '<a href="'.$i->homepage.'" title="'.$i->title.'" hreflang="'.$i->lang.'">Home page</a> ';
      }
      if ($i->landingPage) {
        echo '<a href="'.$i->landingPage.'" title="'.$i->title.'" hreflang="'.$i->lang.'">Landing page</a> ';
      }
      if ($i->downloadURL) {
        echo '<a href="'.$i->downloadURL.'" title="'.$i->title.'" hreflang="'.$i->lang.'">Download</a>';
      }
      if ($i->format != 'HTML') {
        echo ' ('.$i->format.')';
      }
      echo '</dd>';
      if ($i->issued) {
        echo '<dd class="issued">Date: '.$i->issued.'</dd>';
      }
      if ($i->creator) {
        echo '<dd class="creator">Creator: '.$i->creator.'</dd>';
      }
      if ($i->backgroundStudyURL) {
        echo '<dd class="backgroundStudy">Background Study: <a href="'.$i->backgroundStudyURL.'" title="'.$i->backgroundStudyTitle.'" hreflang="'.$i->lang.'">'.$i->backgroundStudyTitle.'</a>, '.$i->backgroundStudyAuthors.', '.$i->backgroundStudyDate.'</dd>';
      }
//      echo '<dd><label>Show/Hide BPs <input class="showHide" type="checkbox" id="showHideBPsFor'.$i->id.'"></label>';
      echo '<dd>';
      listImplementedBPs($i->id);
      echo '</dd></dl>';
    }
  }
}


function  listImplementedBPs($guide) {			// Writes all the BPs cited in a given guide
  global $impList;
  global $base;
  global $w3Base;
  global $bpList;
  echo '<ul id="BPsIn'.$guide.'">';
  foreach ($impList as $i) {
    if ($i->id == $guide) {				// Avoid empty entries
      foreach ($i->BPs as $guideBP) {			// Go through this guide's BPs
        foreach ($bpList as $b) {      			// Looping through the BPs
          if ($guideBP->id == $b->id) {			// we have a match, write the list element
            echo '<li class="';
            if ($b->src == 's') {
              echo 'share-psi"><a href="'.$base.$b->id.'/">';
            } else {
              echo 'w3c"><a href="'.$w3Base.$b->id.'">';
            }
            echo $b->title.'</a> see ';
            if(isset($guideBP->url)) {    // Most of the time we have a URL
              echo '<a href="'.$guideBP->url.'"';
              if((isset($guideBP->lang)) && (isset($guideBP->comment))) {
                echo ' lang="'.$guideBP->lang.'" hreflang="'.$guideBP->lang.'"';
              } else if (isset($guideBP->lang)) {
                echo ' hreflang="'.$guideBP->lang.'"';
              }
              echo '>';
              if (isset($guideBP->comment)) {
                echo $guideBP->comment;
              } else if (($i->format == 'PDF') && (strpos($guideBP->url,'#page='))) {	// We have a PDF, find the page number if present
                $pageNo = substr($guideBP->url, strpos($guideBP->url,'#page=')+1);
                echo strtr($pageNo, '=', ' ');
              } else {
                echo $guideBP->url;
              }
              echo '</a>';
            } else {          // If no URL, just write the comment
              echo $guideBP->comment;
            }
            echo '</li>';
          }
        }
      }
    }
  }
  echo '</ul>';
}

function tabulateBPimplementations() { 			// Writes out a table of the BPs cf their implmentations
  global $impList;
  global $base;
  global $w3Base;
  global $bpList;

  echo '<table id="implementationsTable"><tr><th class="thGuide">Guide</th><th>Area Covered</th>';	// Set up the table
  foreach ($bpList as $b) {
    if ($b->src == 's') {
      echo '<th class="implementation"><a href="'.$base.$b->id.'/" title="'.$b->title.'">'.$b->id.'</a></th>';
      $impCounter[$b->id] = 0;
    }
  }
  echo '</tr>';
  foreach ($impList as $i) {				// Now go through the guides
    echo '<tr><td class="guide"><a href="#'.$i->id.'">'.$i->title.'</a></td><td>'.$i->spatial.'</td>';
    foreach ($bpList as $b) {				// And for each guide, we go through the list of BPs and look for matches
      // is $b->id among the ids in the guide's list?
      if ($b->src == 's') {
        echo '<td>';
        foreach ($i->BPs as $guideBP) {
          if ($guideBP->id == $b->id) {
            echo '&#10004;';
            $impCounter[$b->id]++;
          }
        }
        echo '</td>';
      }
    }
    echo '</tr>';
  }
  echo '<tr><th colspan="2" rowspan="2">Totals</th>';
  foreach ($bpList as $b) {
    if ($b->src == 's') {
      echo '<td class="counter">'.$impCounter[$b->id].'</td>';
    }
  }
  echo '</tr><tr>';	// Repeat the headings
  foreach ($bpList as $b) {
    if ($b->src == 's') {
      echo '<th class="implementation"><a href="'.$base.$b->id.'/" title="'.$b->title.'">'.$b->id.'</a></th>';
    }
  }
  echo '</tr></table>';
}

// List the guides that cite a given BP.
function listThisBPImplementations($bp) {
  global $impList;
  echo '<section id="guides"><h2>Localised Guidance</h2><p>This Best Practice is cited by, or is consistent with, the advice given within the following guides:</p><ul>';
  foreach ($impList as $i) { // Go through the guides
    foreach ($i->BPs as $guideBP) {  // Go through the BPs that this guide covers
      if ($guideBP->id == $bp) {
        if (strpos($i->lang, 'en')) {				# Deal with multilingual titles
          echo '<li class="lgTitle" id="'.$i->id.'">('.$i->group.') <a href="/2013/share-psi/lg/'.$i->group.'#'.$i->id.'">'.$i->title.'</a></li>';
        } else {
          echo '<li  class="lgTitle" id="'.$i->id.'" lang="'.$i->lang.'">('.$i->group.') <a href="/2013/share-psi/lg/'.$i->group.'#'.$i->id.'" hreflang="'.$i->lang.'">'.$i->title.'</a> <span class="translation" lang="en">'.$i->titleEN.'</li>';
        }
      }
    }
  }
  echo '</ul></section>';
}

// Writes boilerplate at the top of BPs to include schema.org markup.
function writeBoilerPlate() {
  echo '<p>This is one of <span itemprop="isPartOf" itemtype="http://schema.org/CreativeWork"> <a href="/2013/share-psi/bp/#bps">a set of Best Practices</a> for implementing the <a itemscope itemprop="about" itemtype="http://schema.org/CreativeWork" href="https://ec.europa.eu/digital-single-market/legal-rules"><span itemprop="name">(Revised) PSI Directive</span></span></a> developed by the <a href="http://www.w3.org/2013/share-psi/" itemprop="author" itemscope itemtype="http://schema.org/Organization"><span itemprop="name">Share-PSI 2.0 Thematic Network</span></a>.</p>';

}


?>